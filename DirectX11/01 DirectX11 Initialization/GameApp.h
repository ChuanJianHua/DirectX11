#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "d3dApp.h"
#include "LightHelper.h"
#include "Geometry.h"
using namespace DirectX;

class GameApp : public D3DApp
{
public:
	struct VSConstantBuffer
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX proj;
		XMMATRIX worldInvTranspose;
	};

	struct PSConstantBuffer
	{
		DirectionalLight dirLight;
		PointLight pointLight;
		SpotLight spotLight;
		Material material;
		XMFLOAT4 eyePos;
	};

public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

private:
	bool InitEffect();
	bool InitResource();
	bool SetMash(const Geometry::MeshData<VertexPosNormalColor>& meshData);


private:
	ComPtr<ID3D11InputLayout> m_pVertexLayout;   // �������벼��
	ComPtr<ID3D11Buffer> m_pIndexBuffer;		 // ����������
	ComPtr<ID3D11Buffer> m_pConstantBuffer[2];	 // ����������
	ComPtr<ID3D11Buffer> m_pVertexBuffer;		 // ���㻺����
	UINT m_IndexCount;							 // ��������

	ComPtr<ID3D11VertexShader> m_pVertexShader;	 // ������ɫ��
	ComPtr<ID3D11PixelShader> m_pPixelShader;	 // ������ɫ��
	VSConstantBuffer m_VSConstantBuffer;		 // ����ConstantBuffer
	PSConstantBuffer m_PSConstantBuffer;		 // ����ConstantBuffer


	DirectionalLight m_DirLight;
	PointLight m_PointLight;
	SpotLight m_SpotLight;
};


#endif