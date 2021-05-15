#include "Header.hlsli"

float4 PS(VertexOut pIn) : SV_TARGET
{
    float3 toEye = normalize((g_EyePos - pIn.posW));
    float4 ambient = 0.0;
    float4 diffuse = 0.0;
    float4 specular = 0.0;
    ComputeDirectionalLight(g_DirLight, g_Material, pIn.normal, toEye, ambient, diffuse, specular);
    return ambient + diffuse + specular;
}