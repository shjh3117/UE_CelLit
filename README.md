# **Custom stylized shader plugin for Unreal Engine 5.7.x**
![ToonCharacterWithDynamicLight](https://github.com/user-attachments/assets/f12d91cf-191f-44b6-bb6b-302003e2211c)

## Supported
- Lumen
- PBR
- VSM

## Unsupported
- Substrate
- Path Tracing
- Mega Light

## Change Log
1. **Removed SDF Shadow for Face**
   The SDF-based facial shadow has been removed, as it only responded properly to horizontal lighting, which felt limiting.
   Instead, the face normals were adjusted to generally face forward. However, since `WorldNormal` also affects other PBR elements, abrupt normal gradients were undesirable. To address this, support for a `FakeNormal` was added, affecting only the BxDF while preserving stable WorldNormal behavior for other shading components.

2. **Unified FaceSkin and BodySkin Shading Model**
   `FaceSkin` and `BodySkin` now use the same Shading Model.

3. **Lumen Global Illumination Adjustments**
   Experiments were conducted with forcing the normal direction to face the camera for Lumen GI. However, this caused reflected objects to appear as if viewed from the camera direction, which is not ideal.
   As a temporary solution, only certain aspects of Lumen’s `WorldNormal` were adjusted to face the camera. Lumen remains complex and requires further refinement.

4. **Improved Hair Occlusion**
   The initial idea was to leverage UE’s VSM-based transmission simulation to remove self-occlusion effects cast near the face. However, this also removed hair occlusion unintentionally.
   To compensate, hair is captured separately, blurred appropriately, and then fed into the Hair Material’s `Opacity` input. This produces a lighting-responsive hair occlusion effect to a reasonable degree.

5. **Outline Improvements**
   The outline rendering has been refined. It now maintains consistent thickness even when different Shading Models are rendered behind the object.

6. **Angel Ring Added**
   An angel ring effect was implemented, though the result is not entirely satisfactory.

7. **Eye Highlight Added**
   An eye highlight effect was implemented, but the current result is not entirely satisfactory. A more accurate approach might involve generating a fake spherical normal from a specific `WorldPosition`, but I’m not very confident with the math required for that approach.
   The current implementation relies on UV manipulation and still requires further improvement.
