it's still in development.

# **Custom cel-shading style shader plugin for Unreal Engine 5**  
https://github.com/user-attachments/assets/b1e32b11-212a-4019-8154-72a91ed1c355  

**CelLit** is a simple **cel-shading style shader** implemented in Unreal Engine 5.6.0  

## View in Other Languages
- [English](README.md)
  
## Key Features

- **Discrete shading based on both direct and indirect lighting (Lumen)**  
![Discrete shading based on both direct and indirect lighting 1](https://github.com/user-attachments/assets/d93cbfd2-6393-4165-b5d2-03f37d9d795b)  
![Discrete shading based on both direct and indirect lighting 2](https://github.com/user-attachments/assets/6eaa1e6a-b6d9-4fd6-ba79-9dd8258ffd65)

In the case of Lumen indirect lighting, the lighting result is simply divided into discrete intervals. Due to noticeable noise, the result is passed through a Gaussian kernel. Please note that any modification in this part must be made in HLSL.

- **Compatible with UE5's PBR**  
![Compatible with UE5's PBR](https://github.com/user-attachments/assets/d86cb5d8-84e4-4a40-9272-2f369359e1f7)  
Since only the CustomData buffer (D) in the GBuffer is modified, Unreal Engine’s built-in PBR system continues to work as expected—regardless of the final visual output.

- **Specialized features for facial shading**  
  - **Directional facial shadow map & reduction of self-shadowing artifacts**  
![Directional shadow map](https://github.com/user-attachments/assets/431dce3e-223b-4020-a167-79e47b60366f)  
![Self-shadowing reduction](https://github.com/user-attachments/assets/8d45bed4-11c2-4d92-9657-447f69e884ec)  
Plugin users are required to prepare a facial shadow map. The plugin includes default shadow maps for VRoid characters. Two maps are needed: one for lighting from above, and one for lighting from below.

  - **Fake Hair Shadow (using custom stencil buffer and scene capture)**  
![Fake Hair Shadow](https://github.com/user-attachments/assets/7666c919-2f18-4045-a6ae-85f0d5874a68)  
Due to limited buffer availability, the AO buffer was repurposed for this effect. However, if the AO map must be used, setting its maximum value to below 0.99 allows the AO functionality to work without issues. The impact on accuracy is not yet confirmed.

- **A simple post-process material for outlining is provided**  
The outline effect is based on depth detection and includes a few minor enhancements. As it is not directly related to internal rendering, you may consider replacing it with a higher-quality material if needed.


## Specification
- **Compatible Features**  
  Lumen (supports both hardware and software ray tracing)  
  Virtual shadow maps (Due to an inherent issue with VSM, when the light incidence angle is between 89 and 90 degrees, the shadow appears sliced. I was able to fix this by adjusting the ShadowBias appropriately, but it does not work well for large meshes.)  
  Physically Based Rendering (Roughness, Metallic, Spacular, AO? I'm not sure what these should represent in toon rendering.)  

- **Incompatible Features**  
  Shader Model 5 (SM5) and below  
  Mobile  
  Ray traced shadows

## Docs
[Wiki](https://github.com/shjh3117/UE_CelLit/wiki)

## Planned Features:  
Improved specular  
~~Face shadow bug fix~~  
Material instances for hair, eyes, etc.  
More appropriate post-processing  
