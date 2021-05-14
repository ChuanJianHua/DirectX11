#include "Light.hlsli"

struct VertexIn
{
    float3 pos : POSITION;
    float3 normal : NORMAL;
    float4 color : COLOR;
};


struct VertexOut
{
    float4 posH : SV_POSITION;
    float3 normal : NORMAL;
    float4 color : COLOR;
};

cbuffer VSConsantBuffer : register(b0)
{
    matrix g_World;
    matrix g_View;
    matrix g_Proj;
    matrix g_WorldInvTranspose;
}

cbuffer PSConsantBuffer : register(b1)
{
    DirectionalLight g_DirLight;
    PointLight g_PointLight;
    SpotLight g_SpotLight;
    Material g_Material;
    float3 g_EyePos;
    float g_Pad;
}