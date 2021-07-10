#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

#include "./Resource.h"
#include "./MeshResource.h"

class __declspec(dllexport) XYY_ModelResource : public XYY_Resource
{
public:
	unsigned int texture_ambient_count = 0;
	unsigned int texture_diffuse_count = 0;
	unsigned int texture_specular_count = 0;
	unsigned int texture_normal_count = 0;
	// model data 
	std::vector<XYY_TextureResource> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	std::vector<XYY_MeshResource>    meshes;
	std::string directory;
	bool gammaCorrection;

	// constructor, expects a filepath to a 3D model.
	XYY_ModelResource(std::string const& path, bool gamma = false);


	// draws the model, and thus all its meshes
	void draw(XYY_ShaderResource& shader);
private:
	// loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
	void loadModel(std::string const& path);
	// processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
	void processNode(aiNode* node, const aiScene* scene);

	XYY_MeshResource processMesh(aiMesh* mesh, const aiScene* scene);

	// checks all material textures of a given type and loads the textures if they're not loaded yet.
	// the required info is returned as a Texture struct.
	std::vector<XYY_TextureResource> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);


};