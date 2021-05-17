#include "Header.hlsli"

VertexOut VS(VertexIn vIn)
{
    VertexOut vOut;
    vOut.posH = mul(float4(vIn.pos, 1.0f), g_World);
    vOut.posW = vOut.posH.xyz;
    vOut.posH = mul(vOut.posH, g_View);
    vOut.posH = mul(vOut.posH, g_Proj);
    vOut.normalW = mul(vIn.normalL, (float3x3)g_WorldInvTranspose);
    vOut.color = vIn.color;
    vOut.tex = vIn.tex;
    return vOut;
}