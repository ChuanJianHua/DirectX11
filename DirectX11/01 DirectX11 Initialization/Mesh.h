#ifndef MESH_H
#define MESH_H
#include <DirectXMath.h>
#include "d3dUtil.h"

struct MeshVertex
{
	DirectX::XMFLOAT3 Position;
	DirectX::XMFLOAT3 Normal;
	DirectX::XMFLOAT2 TexCoords;
	DirectX::XMFLOAT3 Tangent;
};

struct MeshTexture
{
	UINT ID = -1;
	std::string TexturePath;
	std::string TextureUniformName;
};

struct MeshMatProperties
{
	DirectX::XMFLOAT3 AmbientColor;
	DirectX::XMFLOAT3 DiffuseColor;
	DirectX::XMFLOAT3 SpecularColor;
	float Shininess = 0.0f;
	float Refracti = 0.0f;
};

class Mesh
{
public:
	Mesh() = default;
	~Mesh();

	void Init();
private:

};	

#endif // !MESH_H

