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
	ComPtr<ID3D11InputLayout> m_pVertexLayout;   // 顶点输入布局
	ComPtr<ID3D11Buffer> m_pIndexBuffer;		 // 索引缓冲区
	ComPtr<ID3D11Buffer> m_pConstantBuffer[2];	 // 常量缓冲区
	ComPtr<ID3D11Buffer> m_pVertexBuffer;		 // 顶点缓冲区
	UINT m_IndexCount;							 // 顶点数量

	ComPtr<ID3D11VertexShader> m_pVertexShader;	 // 顶点着色器
	ComPtr<ID3D11PixelShader> m_pPixelShader;	 // 像素着色器
	VSConstantBuffer m_VSConstantBuffer;		 // 顶点ConstantBuffer
	PSConstantBuffer m_PSConstantBuffer;		 // 像素ConstantBuffer


	DirectionalLight m_DirLight;
	PointLight m_PointLight;
	SpotLight m_SpotLight;
};


#endif