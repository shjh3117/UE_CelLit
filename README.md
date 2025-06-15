A personal project exploring stylized rendering.  
 This content has been translated by AI. Please understand any potential contextual ambiguity.  

# **Custom stylized shader plugin for Unreal Engine 5**
https://github.com/user-attachments/assets/b1e32b11-212a-4019-8154-72a91ed1c355

**CelLit** is a custom shader plugin developed for Unreal Engine 5.6.0, designed to support discrete shading styles for stylized rendering.

## View in Other Languages
- [English](README.md)
  
## Key Features

- **Discrete shading based on both direct and indirect lighting (Lumen)**  
![Discrete shading based on both direct and indirect lighting 1](https://github.com/user-attachments/assets/d93cbfd2-6393-4165-b5d2-03f37d9d795b)  
![Discrete shading based on both direct and indirect lighting 2](https://github.com/user-attachments/assets/6eaa1e6a-b6d9-4fd6-ba79-9dd8258ffd65)  

In the case of Lumen indirect lighting, results are segmented into discrete intervals. Due to significant noise, a Gaussian kernel is applied for smoothing. Please note that modifications in this section must be implemented in HLSL.

- **Compatible with UE5's PBR**  
![Compatible with UE5's PBR](https://github.com/user-attachments/assets/d86cb5d8-84e4-4a40-9272-2f369359e1f7)  

Since only the `CustomData.D` channel of the GBuffer is modified, Unreal Engine's native PBR system remains functional, regardless of the stylized visual output.

- **Specialized features for facial shading**  
  - **Directional facial shadow map & reduction of self-shadowing artifacts**  
![Directional shadow map](https://github.com/user-attachments/assets/431dce3e-223b-4020-a167-79e47b60366f)  
![Self-shadowing reduction](https://github.com/user-attachments/assets/8d45bed4-11c2-4d92-9657-447f69e884ec)  

Users are expected to prepare facial shadow maps. The plugin includes default shadow maps optimized for VRoid characters. Two maps are required—one for lighting from above, and another for lighting from below.

  - **Fake Hair Shadow (using custom stencil buffer and scene capture)**  
![Fake Hair Shadow](https://github.com/user-attachments/assets/7666c919-2f18-4045-a6ae-85f0d5874a68)  

Due to limited buffer availability, the AO buffer is repurposed for this feature. However, if AO maps are necessary, setting the maximum AO value below 0.99 enables concurrent usage with minimal conflict. The effect on precision is yet to be determined.

- **A simple post-process material for outlining is provided**  
This outline effect is based on depth detection and includes basic enhancements. As it is not tightly integrated with internal shading logic, users are encouraged to replace it with higher-quality outline materials as needed.

## Specification

- **Compatible Features**  
  Lumen (supports both hardware and software ray tracing)  
  Virtual Shadow Maps (Note: Shadows may appear sliced when light incidence is between 89–90 degrees; this can be alleviated by adjusting the ShadowBias value, though results may vary for large meshes.)  
  Physically Based Rendering (Roughness, Metallic, Specular, AO—though these may need reinterpretation for stylized rendering)

- **Incompatible Features**  
  Shader Model 5 (SM5) and below  
  Mobile platforms  
  Ray-traced shadows

## [Qucik Start & Dock]
[Wiki](https://github.com/shjh3117/UE_CelLit/wiki)

## Planned Features:  
Improved specular  
~~Face shadow bug fix~~  
Material instances for hair, eyes, etc.  
Better-suited post-process enhancements
