#include "Lighting.hlsli"

Texture2D gTex : register(t0);
SamplerState gSampler : register(s0);

struct VertexIn
{
    float3 pos : POSITION;
    float3 normalL : NORMAL;
    float4 color : COLOR;
    float2 tex : TEXCOORD;
};


struct VertexOut
{
    float4 posH : SV_POSITION;
    float3 posW : POSITIONT;
    float3 normalW : NORMAL;
    float4 color : COLOR;
    float2 tex : TEXCOORD;
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