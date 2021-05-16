#include "Header.hlsli"

float4 PS(VertexOut pIn) : SV_TARGET
{
    pIn.normalW = normalize(pIn.normalW);
    float3 toEye = normalize((g_EyePos - pIn.posW));
    float4 ambient = 0.0;
    float4 diffuse = 0.0;
    float4 specular = 0.0;
    ComputeDirectionalLight(g_DirLight, g_Material, pIn.normalW, toEye, ambient, diffuse, specular);
    
    float4 lightColor = pIn.color * (ambient + diffuse) + specular;
    lightColor.a = g_Material.Ambient * pIn.color.a;
    return lightColor;
}