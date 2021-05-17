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

void ComputePointLight(PointLight light, 
    Material material, 
    float3 normal, 
    float3 pos,
    float3 toEye,
    out float4 ambient,
    out float4 diffuse,
    out float4 specular)
{
    ambient = float4(0.0f, 0.0f, 0.0f, 0.0f);
    diffuse = float4(0.0f, 0.0f, 0.0f, 0.0f);
    specular = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float3 lightDir = pos - light.Position;
    float distance = length(lightDir);

    if (distance > light.Range)
        return;
    
    lightDir /= distance;
    float diffuseFactor = dot(-lightDir, normal);
  
    ambient = light.Ambient * material.Ambient;
    [flatten]    
    if (diffuseFactor > 0.0f)
    {
        diffuse = light.Diffuse * material.Diffuse * diffuseFactor;
        float3 reflectDir = reflect(lightDir, normal);
        float specularFactor = pow(max(dot(reflectDir, toEye), 0.0f), material.Specular.w);
        specular = material.Specular * light.Specular * specularFactor;
    }
    
    float att = 1 / dot(light.Att, float3(1, distance, distance * distance));
    
    ambient *= att;
    diffuse *= att;
    specular *= att;
}

void ComputeSpotLight(SpotLight light,
    Material material,
    float3 normal,
    float3 pos,
    float3 toEye,
    out float4 ambient,
    out float4 diffuse,
    out float4 specular)
{
    ambient = float4(0.0f, 0.0f, 0.0f, 0.0f);
    diffuse = float4(0.0f, 0.0f, 0.0f, 0.0f);
    specular = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float3 lightDir = pos - light.Position;
    float distance = length(lightDir);

    if (distance > light.Range)
        return;
    
    lightDir /= distance;
    float diffuseFactor = dot(-lightDir, normal);
  
    ambient = light.Ambient * material.Ambient;
    [flatten]    
    if (diffuseFactor > 0.0f)
    {
        diffuse = light.Diffuse * material.Diffuse * diffuseFactor;
        float3 reflectDir = reflect(lightDir, normal);
        float specularFactor = pow(max(dot(reflectDir, toEye), 0.0f), material.Specular.w);
        specular = material.Specular * light.Specular * specularFactor;
    }
    
    float spot = pow(max(dot(lightDir, light.Direction), 0.0f), light.Spot);
    float att = 1 / dot(light.Att, float3(1, distance, distance * distance));

    ambient *= spot;
    diffuse *= att;
    specular *= att;
}
