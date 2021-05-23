#include "Model.h"
#include <iostream>


Model::Model(const std::string& pFile)
{
	loadModel(pFile);
}

Model::~Model()
{
}

bool Model::loadModel(const std::string& pFile)
{
    // Create an instance of the Importer class
    Assimp::Importer importer;

    // And have it read the given file with some example postprocessing
    // Usually - if speed is not the most important aspect for you - you'll
    // probably to request more postprocessing than we do in this example.
    m_pScene = importer.ReadFile(pFile,
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType);
    // If the import failed, report it
    if (!m_pScene) {
        std::cerr << "Error::Model:: " << importer.GetErrorString() << std::endl;
        return false;
    }

    m_Directory = pFile.substr(0, pFile.find_last_of('/'));
    return true;
}

void Model::processVertex(const aiMesh& aiMesh, std::vector<MeshVertex>& vertices)
{
}

void Model::processIndices(const aiMesh& aiMesh, std::vector<UINT>& indices)
{
}

void Model::processTextures(const aiMesh& aiMesh, std::vector<MeshTexture>& textures)
{
}

void Model::processMatProperties(const aiMesh& aiMesh, std::vector<MeshMatProperties>& matProperties)
{
}
