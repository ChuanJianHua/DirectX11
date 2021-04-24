#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "d3dApp.h"

class GameApp : public D3DApp
{
public:
	struct Vertex1
	{
		DirectX::XMFLOAT3 pos;
		DirectX::XMFLOAT4 color;
		static const D3D11_INPUT_ELEMENT_DESC inputLayout[2];
	};

	struct Vertex2
	{
		DirectX::XMFLOAT3 pos;
		DirectX::XMFLOAT3 normal;
		DirectX::XMFLOAT4 color;
		DirectX::XMFLOAT2 tex0;
		DirectX::XMFLOAT2 tex1;
		static const D3D11_INPUT_ELEMENT_DESC inputLayout[5];
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


private:
	ComPtr<ID3D11InputLayout> m_pVertexLayout;   // 顶点输入布局
	ComPtr<ID3D11Buffer> m_pVertexBuffer;		 // 顶点缓冲区
	ComPtr<ID3D11VertexShader> m_pVertexShader;	 // 顶点着色器
	ComPtr<ID3D11PixelShader> m_pPixelShader;	 // 像素着色器
};


#endif