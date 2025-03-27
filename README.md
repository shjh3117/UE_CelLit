Since it's still in development, there are a few issues to be addressed. I'll fix it.

# **Custom cel-shading style shader plugin for Unreal Engine 5**  
![image](https://github.com/user-attachments/assets/7f6499cb-f121-48c4-b890-7fef917d15d5)

**CelLit** is a simple **cel-shading style shader** implemented in Unreal Engine 5.5.x

## View in Other Languages
- [English](README.md)
  
## Introduction
This shader applies lighting effects in the cartoon of manga or animation.  
It modifies the HLSL code of the engine's preintergrated skin shading model and cloth shading model, so requiring the engine's shader code to be replaced.  
CelLit Shader offers the following key features:   

- **Cel Rendering**  
![image](https://github.com/user-attachments/assets/66d64d91-9b88-44de-b423-08b1c2717e1e)
![image-ezgif com-resize](https://github.com/user-attachments/assets/5619a1aa-3b7e-4d6c-b600-0a16f2385a36)  
  Cartoon-like shading for surfaces lit by direct lighting.  
  Supports Mult-tone Shading(2-10 tone).  
  Supports Shadow threshold map.  <- I implemented this using local matrices, so it adapts to all angles. It is applied not only horizontally but also vertically. but there are still some bugs.  
  Supports Virtual texure drawing to control normal.  <-- 
  Reduces self-shadowing using opacity.  
  Compatible with all types of lighting.  
  Compatible with transmission.  
  Compatible with PBR.  

- **Cel Global Illumination Rendering**  
  ![20241231-0422-08 2373269-ezgif com-resize](https://github.com/user-attachments/assets/39da4092-d2cb-4790-83d0-4513dff94a0e) ![Screenshot2024-12-31153322-ezgif com-resize](https://github.com/user-attachments/assets/a2db7a80-8c63-4d67-89cb-20a9abf210af) ![Screenshot2025-01-01172558-ezgif com-resize](https://github.com/user-attachments/assets/fe3abbf7-48d6-44dc-9cdf-693a3e9100b8)  

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
