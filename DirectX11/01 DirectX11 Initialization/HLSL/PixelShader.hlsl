#include "Header.hlsli"

float4 PS(VertexOut pIn) : SV_TARGET
{
    pIn.normalW = normalize(pIn.normalW);
    float3 toEye = normalize((g_EyePos - pIn.posW));
    float4 ambient = 0.0;
    float4 diffuse = 0.0;
    float4 specular = 0.0;
    float4 a = 0.0;
    float4 d = 0.0;
    float4 s = 0.0;
    ComputeDirectionalLight(g_DirLight, g_Material, pIn.normalW, toEye, a, d, s);
    ambient += a;
    diffuse += d;
    specular += s;
    ComputePointLight(g_PointLight, g_Material, pIn.normalW, pIn.posW, toEye, a, d, s);
    ambient += a;
    diffuse += d;
    specular += s;
    ComputeSpotLight(g_SpotLight, g_Material, pIn.normalW, pIn.posW, toEye, a, d, s);
    ambient += a;
    diffuse += d;
    specular += s;
    float4 lightColor = pIn.color * (ambient + diffuse) + specular;
    lightColor.a = g_Material.Ambient * pIn.color.a;
    float3 textureColor = gTex.Sample(gSampler, pIn.tex);
    return lightColor * float4(textureColor, 1.0f);
}