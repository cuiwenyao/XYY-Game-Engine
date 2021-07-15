#include "./CubeElement.h"


XYY_CubeElement::XYY_CubeElement(XYY_ShaderResource * shader, unsigned int type , glm::vec3 position, glm::vec3 scale, float angle, glm::vec3 rotation )
{
	ld_rend = new XYY_LocalRendDriver();
	ld_rend->type = 1;
	ld_rend->cube = new XYY_CubeResource();
	ld_rend->shader = shader;
	// shader = new XYY_ShaderResource("GLSL/object.vert", "GLSL/object.frag");

	// this->type = type;		//设置元素类型
	ld_rend->setposition(position);
	ld_rend->scale = scale;

	ld_rend->modelmat = glm::mat4(1.0f);
	ld_rend->modelmat = glm::translate(ld_rend->modelmat, position);
	ld_rend->modelmat = glm::scale(ld_rend->modelmat, scale);
	ld_rend->modelmat = glm::rotate(ld_rend->modelmat, glm::radians(angle), rotation);

}

void XYY_CubeElement::addtexture(const std::string& texturepath, unsigned int texturetype)
{
	ld_rend->cube->attachtexture(texturepath, texturetype);
}

void XYY_CubeElement::addtexture(XYY_TextureResource * texture)
{
	ld_rend->cube->attachtexture(texture);
}