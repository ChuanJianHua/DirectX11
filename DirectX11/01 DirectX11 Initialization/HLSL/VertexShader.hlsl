#include "Header.hlsli"

VertexOut VS(VertexIn pIn)
{
    VertexOut pOut;
    pOut.posH = float4(pIn.pos, 1.0f);
    pOut.color = pIn.color;
    return pOut;
}