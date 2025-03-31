Since it's still in development, there are many issues to be addressed. I'll fix it.

# **Custom cel-shading style shader plugin for Unreal Engine 5**  
https://github.com/user-attachments/assets/b1e32b11-212a-4019-8154-72a91ed1c355

**CelLit** is a simple **cel-shading style shader** implemented in Unreal Engine 5.5.x

## View in Other Languages
- [English](README.md)
  
## Introduction
This shader applies lighting effects in the cartoon of manga or animation.  
It modifies the HLSL code of the engine's preintergrated skin shading model and cloth shading model, so requiring the engine's shader code to be replaced.  
CelLit Shader offers the following key features:   

- **Cel Rendering**  
![image](https://github.com/user-attachments/assets/66d64d91-9b88-44de-b423-08b1c2717e1e)
![image](https://github.com/user-attachments/assets/d48658db-e579-4072-a6d8-e7914df16aa8)  
  Cartoon-like shading for surfaces lit by direct lighting.  
  Supports Mult-tone Shading(2-10 tone).  
  Supports Shadow threshold map.  <- I implemented this using local matrices, so it adapts to all angles. It is applied not only horizontally but also vertically. but there are still some bugs.  
  Supports Virtual texure drawing to control normal.  <-- 
  Reduces self-shadowing using opacity.  
  Compatible with all types of lighting.  
  Compatible with transmission.  
  Compatible with PBR.  

- **Cel Global Illumination Rendering**  
![image](https://github.com/user-attachments/assets/027efb89-a434-4478-89d4-94c5f97abd27)
![image](https://github.com/user-attachments/assets/a0974b52-36d0-41f8-9ac9-3b52ad72c7d8)
![image](https://github.com/user-attachments/assets/b4ca1fa8-d18b-43c4-b083-2c53ca3d6d0d)  
  Cartoon-like shading for surfaces lit by indirect lighting (multi-tone shading).  
  Compatible with Lumen indirect lighting (Ex. Lit by Emissive Color).  
  Noise Attenuation through Low-Frequency Filtering.  
  
- **OutLine**  
  Provides a post-process material using Sobel filtering for edge detection.  

## Specification
- **Compatible Features**  
  Lumen (supports both hardware and software ray tracing)  
  Virtual shadow maps (VSM)  
  Physically Based Rendering (PBR)  
    
- **Incompatible Features**  
  Shader Model 5 (SM5) and below  
  Mobile  
  Ray traced shadows

## Docs
I'll make...

## Planned Features:  
Improved specular  
Face shadow bug fix  
Shaders suitable for hair, eyes, etc.  
More appropriate post-processing  
  
## Installation
This shading was implemented by modifying the engine's shader code.  
I also developed a plugin that replaces the relevant shader files. The plugin includes appropriate material assets.  
It can be applied like a regular plugin; however, a shader rebuild is required after applying it. **(Ctrl + Shift + .)**  
The plugin is designed to restore the original shader files when the engine shuts down. However, in case of a forced shutdown, the restoration may not occur.  
If this happens, you can restore the files by verifying the engine through the Epic Games Launcher.  

## Usage
  Cloth Shading Model is a normal CelLit Material.  
  Preintergrated skin Shading Model is for face shading.  
  I recommend using /content/material/M_CelLit, and M_CelLit_face in SampleProject.  
  The plugin contains appropriate material assets.  
