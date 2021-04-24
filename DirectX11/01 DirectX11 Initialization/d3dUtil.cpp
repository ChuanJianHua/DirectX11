#include "d3dUtil.h"

using namespace std::filesystem;

HRESULT CreateShaderFromFile(
    const WCHAR* csoFileNameInOut,
    const WCHAR* hlslFileName,
    LPCSTR entryPoint, 
    LPCSTR shaderModel, 
    ID3DBlob** ppBlobOut)
{
    HRESULT hr = S_OK;

    if (csoFileNameInOut && exists(csoFileNameInOut))
    {
        return D3DReadFileToBlob(csoFileNameInOut, ppBlobOut);
    }
    else 
    {
        DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#ifdef _DEBUG
        // 设置 D3DCOMPILE_DEBUG 标志用于获取着色器调试信息。该标志可以提升调试体验，
        // 但仍然允许着色器进行优化操作
        dwShaderFlags |= D3DCOMPILE_DEBUG;

        // 在Debug环境下禁用优化以避免出现一些不合理的情况
        dwShaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

        ID3DBlob* errorBlob = nullptr;
        hr = D3DCompileFromFile(hlslFileName, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, entryPoint, shaderModel, dwShaderFlags, 0, ppBlobOut, &errorBlob);
        if (FAILED(hr))
        {
            if (errorBlob != nullptr)
            {
                OutputDebugStringA(reinterpret_cast<const char*>(errorBlob->GetBufferPointer()));
            }
            SAFE_RELEASE(errorBlob);
            return hr;
        }

        if (csoFileNameInOut)
        {
            return D3DWriteBlobToFile(*ppBlobOut, csoFileNameInOut, false);
        }
    }
    return hr;
}
