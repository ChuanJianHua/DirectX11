#pragma once D3DAPP_H


//添加所有需要引用的库
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "D3DCompiler.lib")
#pragma comment(lib, "winmm.lib")

class D3DApp
{
public:
	D3DApp();
	virtual ~D3DApp();

private:

};

D3DApp::D3DApp()
{
}

D3DApp::~D3DApp()
{
}
