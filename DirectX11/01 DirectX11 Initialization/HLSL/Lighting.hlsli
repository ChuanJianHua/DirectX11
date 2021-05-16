#include "Light.hlsli"

void ComputeDirectionalLight(DirectionalLight light, Material material, float3 normal, float3 toEye,
    out float4 ambient, out float4 diffuse, out float4 specular)
{
    
    ambient = float4(0.0f, 0.0f, 0.0f, 0.0f);
    diffuse = float4(0.0f, 0.0f, 0.0f, 0.0f);
    specular = float4(0.0f, 0.0f, 0.0f, 0.0f);
    
    float3 lightDir = light.Direction;
    ambient = light.Ambient * material.Ambient;
    
    float diffuseFactor = dot(-lightDir, normal);
    [flatten]    
    if (diffuseFactor > 0.0f)
    {
        diffuse = light.Diffuse * material.Diffuse * diffuseFactor;
        float3 reflectDir = reflect(lightDir, normal);
        float specularFactor = pow(max(dot(reflectDir, toEye), 0.0f), material.Specular.w);
        specular = material.Specular * light.Specular * specularFactor;
    }
}

void ComputePointLight()
{
    
}

void ComputeSpotLight()
{
    
}
