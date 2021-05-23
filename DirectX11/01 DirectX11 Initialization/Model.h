#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include "Mesh.h";
#include <vector>;
#include <string>;
#include <Assimp/Importer.hpp>      // C++ importer interface
#include <Assimp/scene.h>           // Output data structure
#include <Assimp/postprocess.h>     // Post processing flags

class Model
{
public:
	Model() = default;
	Model(const std::string &pFile);
	~Model();

private:

	const aiScene		  *m_pScene;
	std::string			  m_Directory;
	std::shared_ptr<Mesh> m_mesh;
	std::vector<Mesh>	  m_Meshes;

	bool loadModel(const std::string& path);
	void processVertex(const aiMesh &aiMesh, std::vector<MeshVertex> &vertices);
	void processIndices(const aiMesh& aiMesh, std::vector<UINT>& indices);
	void processTextures(const aiMesh& aiMesh, std::vector<MeshTexture>& textures);
	void processMatProperties(const aiMesh& aiMesh, std::vector<MeshMatProperties>& matProperties);

};

#endif // !MODEL_H


