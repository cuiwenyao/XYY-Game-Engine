#version 330 core
out vec4 FragColor;

in vec3 Pos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 objectcolor;

uniform int texture_ambient_count;
uniform sampler2D texture_ambient[10];

uniform int texture_diffuse_count;
uniform sampler2D texture_diffuse[10];

uniform int texture_specular_count;
uniform sampler2D texture_specular[10];

uniform int texture_normal_count;
uniform sampler2D texture_normal[10];


struct DirLight {
    vec3 direction;
	
    vec3 color;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;
    
    vec3 color;

    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    vec3 color;

    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};

//设置点光源的数量
uniform int pointlight_count;
//设置光源的数量
uniform int dirlight_count;
//设置光源的数量
uniform int spotlight_count;

uniform vec3 viewPos;
uniform DirLight dirLight[10];
uniform PointLight pointLight[10]; //设最多有十个点光源
uniform SpotLight spotLight[10]; 
uniform float shininess;
//计算光照
vec4 CalcDirLight(DirLight dirlight, vec3 normal, vec3 viewDir,vec4 ambient,vec4 diffuse,vec4 specular);
vec4 CalcPointLight(PointLight pointlight, vec3 normal, vec3 fragPos, vec3 viewDir,vec4 ambient,vec4 diffuse,vec4 specular);
vec4 CalcSpotLight(SpotLight spotlight, vec3 normal, vec3 fragPos, vec3 viewDir,vec4 ambient,vec4 diffuse,vec4 specular);



void main()
{    
    vec4 ambient=vec4(0,0,0,1);
    vec4 diffuse=vec4(0,0,0,1);
    vec4 specular=vec4(0,0,0,1);
    for(int i=0;i<texture_ambient_count;i++)
    {
         ambient+=texture(texture_ambient[i],TexCoords);
    }
    for(int i=0;i<texture_diffuse_count;i++)
    {
         diffuse+=texture(texture_diffuse[i],TexCoords);
    }
    for(int i=0;i<texture_specular_count;i++)
    {
         specular+=texture(texture_specular[i],TexCoords);
    }

    int texture_count=texture_ambient_count+texture_diffuse_count+texture_specular_count;

    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - Pos);

    vec4 result;
    if(texture_count==0)
    {
        result=vec4(objectcolor,1);
        ambient=result/3.0f;
        diffuse=result/3.0f;
        specular=result/3.0f;
    }
    else
        result=vec4(ambient+diffuse+specular)/(texture_count);

    for(int i = 0; i < pointlight_count; i++)
        result += CalcPointLight(pointLight[i], norm, Pos, viewDir,ambient,diffuse,specular);    
    for(int i = 0; i < dirlight_count; i++)
        result += CalcDirLight(dirLight[i], norm, viewDir,ambient,diffuse,specular);
    for(int i = 0; i < spotlight_count; i++)
        result += CalcSpotLight(spotLight[i], norm, Pos, viewDir,ambient,diffuse,specular);    


    //result=vec4(pointLight[0].color,1);

    FragColor=result/2.0f;
    //FragColor = vec4(ambient+diffuse+specular)/(texture_ambient_count+texture_diffuse_count+texture_specular_count);


}


// calculates the color when using a directional light.
vec4 CalcDirLight(DirLight dirlight, vec3 normal, vec3 viewDir,vec4 ambient,vec4 diffuse,vec4 specular)
{
    vec3 lightDir = normalize(-dirlight.direction);
    // diffuse shading
    float diff = max(dot(normal, dirlight.direction), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    //反光度
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);

    // combine results
    ambient*=vec4(dirlight.ambient,1);

    diffuse = vec4(dirlight.diffuse,1) * diff * diffuse;
    specular = vec4(dirlight.specular,1) * spec * specular;
    return (ambient + diffuse + specular);
}

// calculates the color when using a point light.
vec4 CalcPointLight(PointLight pointlight, vec3 normal, vec3 fragPos, vec3 viewDir,vec4 ambient,vec4 diffuse,vec4 specular)
{
    vec3 lightDir = normalize(pointlight.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // attenuation
    float distance = length(pointlight.position - fragPos);
    float attenuation = 1.0 / (pointlight.constant + pointlight.linear * distance + pointlight.quadratic * (distance * distance));    
    // combine results
    ambient = vec4(pointlight.ambient,1) * diffuse;
    diffuse = vec4(pointlight.diffuse,1) * diff * diffuse;
    specular = vec4(pointlight.specular,1) * spec * diffuse;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

// calculates the color when using a spot light.
vec4 CalcSpotLight(SpotLight spotlight, vec3 normal, vec3 fragPos, vec3 viewDir,vec4 ambient,vec4 diffuse,vec4 specular)
{
    vec3 lightDir = normalize(spotlight.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // attenuation
    float distance = length(spotlight.position - fragPos);
    float attenuation = 1.0 / (spotlight.constant + spotlight.linear * distance + spotlight.quadratic * (distance * distance));    
    // spotlight intensity
    float theta = dot(lightDir, normalize(-spotlight.direction)); 
    float epsilon = spotlight.cutOff - spotlight.outerCutOff;
    float intensity = clamp((theta - spotlight.outerCutOff) / epsilon, 0.0, 1.0);

    // combine results
    ambient = vec4(spotlight.ambient,1) * diffuse;
    diffuse = vec4(spotlight.diffuse,1) * diff * diffuse;
    specular = vec4(spotlight.specular,1) * spec * diffuse;
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}