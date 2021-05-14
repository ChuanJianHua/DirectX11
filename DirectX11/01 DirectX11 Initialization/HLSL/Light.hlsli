//方向光
struct DirectionalLight
{
    float4 Ambient;
    float4 Diffuse;
    float4 Specular;
    float3 Direction;
    float pad;
};

//点光
struct PointLight
{
    float4 Ambient;
    float4 Diffuse;
    float4 Specular;
    
    float3 Position;
    float Range;
    
    float3 Att;
    float pad;
};


// 聚光灯
struct SpotLight
{
    float4 Ambient;
    float4 Diffuse;
    float4 Specular;

    float3 Position;
    float Range;

    float3 Direction;
    float Spot;

    float3 Att;
    float Pad;
};


// 物体表面材质
struct Material
{
    float4 Ambient;
    float4 Diffuse;
    float4 Specular; // w = SpecPower
    float4 Reflect;
};


