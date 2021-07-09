#include "./ModelResource.h"


// constructor, expects a filepath to a 3D model.
XYY_ModelResource::XYY_ModelResource(std::string const& path, bool gamma) : gammaCorrection(gamma)
{
	loadModel(path);
}

// draws the model, and thus all its meshes
void XYY_ModelResource::draw(XYY_ShaderResource & shader)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].draw(shader);
	// std::cout << "模型渲染完成" << std::endl;
}

// loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
void XYY_ModelResource::loadModel(std::string const& path)
{
	// read file via ASSIMP
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	// check for errors
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	{
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}
	// retrieve the directory path of the filepath
	directory = path.substr(0, path.find_last_of('/'));
	std::cout << "directory: " << directory << std::endl;

	// process ASSIMP's root node recursively
	processNode(scene->mRootNode, scene);
}

// processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
void XYY_ModelResource::processNode(aiNode* node, const aiScene* scene)
{
	// process each mesh located at the current node
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		// the node object only contains indices to index the actual objects in the scene. 
		// the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	// after we've processed all of the meshes (if any) we then recursively process each of the children nodes
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}

}

XYY_MeshResource XYY_ModelResource::processMesh(aiMesh* mesh, const aiScene* scene)
{
	// data to fill
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<XYY_TextureResource> textures;

	// walk through each of the mesh's vertices
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		glm::vec3 vector; // we declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
		// positions
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;
		// normals
		if (mesh->HasNormals())
		{
			vector.x = mesh->mNormals[i].x;
			vector.y = mesh->mNormals[i].y;
			vector.z = mesh->mNormals[i].z;
			vertex.Normal = vector;
		}
		// texture coordinates
		if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
		{
			glm::vec2 vec;
			// a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
			// use models where a vertex can have multiple texture coordinates so we always take the first set (0).
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
			// tangent
			vector.x = mesh->mTangents[i].x;
			vector.y = mesh->mTangents[i].y;
			vector.z = mesh->mTangents[i].z;
			vertex.Tangent = vector;
			// bitangent
			vector.x = mesh->mBitangents[i].x;
			vector.y = mesh->mBitangents[i].y;
			vector.z = mesh->mBitangents[i].z;
			vertex.Bitangent = vector;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);

		vertices.push_back(vertex);
	}
	// now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		// retrieve all indices of the face and store them in the indices vector
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	// process materials
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	// we assume a convention for sampler names in the shaders. Each diffuse texture should be named
	// as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
	// Same applies to other texture as the following list summarizes:
	// diffuse: texture_diffuseN
	// specular: texture_specularN
	// normal: texture_normalN

	// 1. diffuse maps
	std::vector<XYY_TextureResource> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
	{
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		texture_diffuse_count++;
	}
	// 2. specular maps
	std::vector<XYY_TextureResource> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
	{
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		texture_specular_count++;
	}
	// 3. normal maps
	std::vector<XYY_TextureResource> normalMaps = loadMaterialTextures(material, aiTextureType_NORMALS, "texture_normal");
	{
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
		texture_normal_count++;
	}
	// 4. height maps
	std::vector<XYY_TextureResource> heightMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_height");
	textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
	// 5. ambient maps
	std::vector<XYY_TextureResource> ambientMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_ambient");
	{
		textures.insert(textures.end(), ambientMaps.begin(), ambientMaps.end());
		texture_ambient_count++;
	}
	// 6. basecolor maps
	std::vector<XYY_TextureResource> basecolorMaps = loadMaterialTextures(material, aiTextureType_BASE_COLOR, "texture_basecolor");
	textures.insert(textures.end(), basecolorMaps.begin(), basecolorMaps.end());
	// 7. ambientocclusion maps
	std::vector<XYY_TextureResource> ambientocclusionMaps = loadMaterialTextures(material, aiTextureType_AMBIENT_OCCLUSION, "texture_ambientocclusion");
	textures.insert(textures.end(), ambientocclusionMaps.begin(), ambientocclusionMaps.end());
	// 8. diffuseroughness maps
	std::vector<XYY_TextureResource> diffuseroughnessMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE_ROUGHNESS, "texture_diffuseroughness");
	textures.insert(textures.end(), diffuseroughnessMaps.begin(), diffuseroughnessMaps.end());


	//aiTextureType_BASE_COLOR
	//贴图类型有时间增加上去


	// return a mesh object created from the extracted mesh data
	return XYY_MeshResource(vertices, indices, textures);
}

// checks all material textures of a given type and loads the textures if they're not loaded yet.
// the required info is returned as a Texture struct.
std::vector<XYY_TextureResource> XYY_ModelResource::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
	std::vector<XYY_TextureResource> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
	//	std::cout << "正在加载第: " << i << "个" << typeName << std::endl;
		aiString str;
		mat->GetTexture(type, i, &str);
		// check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
		bool skip = false;
		for (unsigned int j = 0; j < textures_loaded.size(); j++)
		{
			if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
			{
				textures.push_back(textures_loaded[j]);
				skip = true;			// a texture with the same filepath has already been loaded, continue to next one. (optimization)
				break;
			}
		}
		if (!skip)
		{   // if texture hasn't been loaded already, load it
			XYY_TextureResource texture;
			texture.path = str.C_Str();
			texture.type = typeName;
			texture.loadmodeltexture(this->directory);
			textures.push_back(texture);
			textures_loaded.push_back(texture);  // store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
		}
	}
	return textures;
}
