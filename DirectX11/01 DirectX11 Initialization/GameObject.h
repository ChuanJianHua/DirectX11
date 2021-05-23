#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <DirectXMath.h>
#include <memory>
#include "Mesh.h"

class Gameobject
{
public:
	Gameobject() = default;
	Gameobject(const std::string &Name);
	virtual ~Gameobject() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;

private:
	std::string m_Name;
	DirectX::XMMATRIX m_ModelMatrix;
	DirectX::XMMATRIX m_TranslationMatrix;
	DirectX::XMMATRIX m_RotationMatrix;
	DirectX::XMMATRIX m_ScaleMatrix;
	DirectX::XMFLOAT3 m_Position;
	DirectX::XMFLOAT3 m_Rotation;
	DirectX::XMFLOAT3 m_Scale;

	void updateModelMatrix();
};
#endif
