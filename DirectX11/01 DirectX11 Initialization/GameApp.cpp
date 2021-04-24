#include "GameApp.h"
#include "d3dUtil.h"
#include "DXTrace.h"
using namespace DirectX;
using namespace std::filesystem;

const D3D11_INPUT_ELEMENT_DESC GameApp::Vertex1::inputLayout[2] = {
	{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
	{"COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
};	

GameApp::GameApp(HINSTANCE hInstance)
	: D3DApp(hInstance)
{
}

GameApp::~GameApp()
{
}

bool GameApp::Init()
{
	if (!D3DApp::Init())
		return false;
	if (!InitEffect())
		return false;
	if (!InitResource())
		return false;
	return true;
}

void GameApp::OnResize()
{
	D3DApp::OnResize();
}

void GameApp::UpdateScene(float dt)
{

}

void GameApp::DrawScene()
{
	assert(m_pd3dImmediateContext);
	assert(m_pSwapChain);
	static float black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };	// RGBA = (0,0,255,255)
	m_pd3dImmediateContext->ClearRenderTargetView(m_pRenderTargetView.Get(), black);
	m_pd3dImmediateContext->ClearDepthStencilView(m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	// 绘制三角形
	m_pd3dImmediateContext->Draw(3, 0);
	HR(m_pSwapChain->Present(0, 0));
}

bool GameApp::InitEffect()
{
	ComPtr<ID3DBlob> blob;

	//创建定点着色器
	HR(CreateShaderFromFile(L"HLSL\\VertexShader.cso", L"HLSL\\VertexShader.hlsl", "VS", "vs_5_0", blob.ReleaseAndGetAddressOf()));
	HR(m_pd3dDevice->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, m_pVertexShader.GetAddressOf()));

	//创建并绑定定点布局
	HR(m_pd3dDevice->CreateInputLayout(Vertex1::inputLayout, ARRAYSIZE(Vertex1::inputLayout), blob->GetBufferPointer(), 
		blob->GetBufferSize(), m_pVertexLayout.GetAddressOf()));

	//创建像素着色器
	HR(CreateShaderFromFile(L"HLSL\\PixelShader.cso", L"HLSL\\PixelShader.hlsl", "PS", "ps_5_0", blob.ReleaseAndGetAddressOf()));
	HR(m_pd3dDevice->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, m_pPixelShader.GetAddressOf()));

	return true;
}

bool GameApp::InitResource()
{
	// 设置三角形顶点
	Vertex1 vertices[] =
	{
		{ XMFLOAT3(0.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
		{ XMFLOAT3(0.5f, -0.5f, 0.5f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
		{ XMFLOAT3(-0.5f, -0.5f, 0.5f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) }
	};

	// 设置顶点缓冲区描述
	D3D11_BUFFER_DESC vbd;
	ZeroMemory(&vbd, sizeof(vbd));
	vbd.Usage = D3D11_USAGE_IMMUTABLE;
	vbd.ByteWidth = sizeof vertices;
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbd.CPUAccessFlags = 0;
	// 新建顶点缓冲区
	D3D11_SUBRESOURCE_DATA initData;
	ZeroMemory(&initData, sizeof(initData));
	initData.pSysMem = vertices;
	HR(m_pd3dDevice->CreateBuffer(&vbd, &initData, m_pVertexBuffer.GetAddressOf()));

	// ******************
	// 给渲染管线各个阶段绑定好所需资源

	// 输入装配阶段的顶点缓冲区设置
	UINT stride = sizeof(Vertex1);	// 跨越字节数
	UINT offset = 0;				// 起始偏移量

	m_pd3dImmediateContext->IASetVertexBuffers(0, 1, m_pVertexBuffer.GetAddressOf(), &stride, &offset);
	// 设置图元类型，设定输入布局
	m_pd3dImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	m_pd3dImmediateContext->IASetInputLayout(m_pVertexLayout.Get());
	// 将着色器绑定到渲染管线
	m_pd3dImmediateContext->VSSetShader(m_pVertexShader.Get(), nullptr, 0);
	m_pd3dImmediateContext->PSSetShader(m_pPixelShader.Get(), nullptr, 0);

	return true;
}
