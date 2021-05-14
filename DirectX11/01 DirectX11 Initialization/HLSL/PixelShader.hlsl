#include "Header.hlsli"

float4 PS(VertexOut pIn) : SV_TARGET
{
    //return pIn.color;
    return float4(pIn.normal, 1.0);

}