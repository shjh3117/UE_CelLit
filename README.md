An individually developed project focusing on stylized rendering.

# **Custom stylized shader plugin for Unreal Engine 5.7.x**
https://github.com/user-attachments/assets/c5684bb8-bc8e-4f75-a79a-8e4123d7cd17


## Supported
- Lumen GI
- PBR
- VSM


## Unsupported
- Substrate
- Path Tracing
- Mega Light
- Lumen Reflection


## Features

- Support Direction Light and Local Lights  
  <img width="513" height="513" alt="Direction Light and Local Lights" src="https://github.com/user-attachments/assets/077770e0-ea57-47f9-b962-0aaa62f3939f" />
  <img width="513" height="513" alt="Screenshot" src="https://github.com/user-attachments/assets/aad34a84-4583-4663-95b8-fe996ba64eed" />

- Support Lumen GI  
  <img width="513" height="513" alt="Lumen GI" src="https://github.com/user-attachments/assets/9ffe03fd-7709-45d9-a56f-cf544e2c52fa" />

- Projected Hair Shadow  
  <img width="513" height="513" alt="image" src="https://github.com/user-attachments/assets/bcaa6517-4533-41be-b76a-11cc427843b0" />

- Toon Style Hiar Highlight  
  <img width="513" height="513" alt="image" src="https://github.com/user-attachments/assets/d79964ec-bb45-44f2-86ae-02df69b80e8f" />

- Toon Style Eye Highlight  
  <img width="513" height="513" alt="image" src="https://github.com/user-attachments/assets/d6b29fb0-2329-416f-be9c-d3238663e7d0" />

- VSM-based Self-Occlusion Suppression

## Change Log
- Implemented Projected Hair Shadow. (The existing opacity reinjection method was removed because it caused frame drops during capture.)


## Notes
- Please Turn off Substrate Material in Project Settings
- It was tested on a MacBook Air (M4).


## Implementation Details

### Shadow Control for NPR Character Rendering

In NPR character rendering, physically accurate shadows are not always desirable.

Even normal-based N·L shading can interfere with the intended 2D character design. For this reason, NPR shaders often replace or reshape the N·L response using artist-controlled data such as SDF face shadow maps, light maps, or edited normals.

Cast shadows can also be problematic. To preserve only the desired cast shadows while avoiding unwanted self-shadowing, some character rendering pipelines compute an additional character-specific shadow or visibility pass, or use a separate stylized shadow mask.

UE_CelLit takes a different approach for suppressing cast shadows on the character face. Instead of adding another shadow pass, it uses Unreal Engine's internal transmission behavior.

In Unreal Engine, the transmission-related shadow behavior can be interpreted as scaling the distance to the first occluder in the shadow map by the material opacity. This is not physically accurate for every case, especially when multiple external occluders are involved. However, it is effective for suppressing short-range self-shadowing.

Conceptually, this works like placing a virtual shell around the shaded point. Occluders inside this local range are attenuated or ignored, which helps reduce unwanted self-shadowing on the face. Since a character face is roughly convex and close to a spherical form, this approximation works well for stylized facial shading.

However, the face still needs intentional cast shadows from the hair. In NPR character rendering, hair cast shadows are often either omitted or stylized separately. UE_CelLit uses the latter approach by dynamically projecting hair occlusion according to the light direction.

Hair pixels are marked through `GBuffer.CustomData`, and the shader samples a projected screen-space position based on the light vector. If the projected sample corresponds to hair, the result is combined with Unreal Engine's shadow term to produce a controlled hair-to-face cast shadow. Additional logic is used to reduce unintended shadows.

### Hair Highlight

The hair highlight is based on a simplified Kajiya-Kay style tangent highlight.

A tangent-like direction is stored in `GBuffer.CustomData.yz` using octahedral encoding. During lighting, this direction is decoded and used to compute a stylized anisotropic highlight. The result is then discretized to create a toon-style hair highlight.

### Eye Highlight

For VRoid-style characters, the actual eye surface can be too far from an ideal spherical shape to produce a desirable specular highlight.

To address this, UE_CelLit generates a virtual eye-sphere normal and uses it for the eye highlight calculation. This creates a more controllable toon-style eye highlight independent of the original mesh normal.

### Outline

The outline is calculated in a post-process pass using Sobel filtering on the depth buffer.

Pixels can be selectively included in the outline calculation through a control bit stored in `GBuffer.CustomData.x`.

### Custom Data Packing

UE_CelLit uses `GBuffer.CustomData.x` as a compact control buffer.

A single 3D vector is octahedrally encoded and stored in `GBuffer.CustomData.yz`. The meaning of this vector depends on the enabled control bit.

| Bit | Name | Description |
|---:|---|---|
| 0 | `UseLambertShadow` | Enables normal-based N·L shading. |
| 1 | `UseDiscreteSurfaceShadow` | Quantizes cast shadow into a stepped toon-style shadow. |
| 2 | `UseEyeHighlight` | Interprets `CustomData.yz` as the eye or iris center viewport UV for toon eye highlight. |
| 3 | `UseHairHighlight` | Interprets `CustomData.yz` as a tangent-like direction for hair highlight. |
| 4 | `UseSubLambertShadow` | Interprets `CustomData.yz` as a replacement normal for stylized N·L shading. This avoids modifying Unreal Engine's main world normal, which is shared by many rendering features. |
| 5 | `UseOutline` | Marks the pixel as part of the outline target in the post-process outline pass. |
| 6 | Reserved | Previously used by a removed feature. |
| 7 | `IsHair` | Marks the pixel as hair for projected hair shadow and hair-related effects. |
