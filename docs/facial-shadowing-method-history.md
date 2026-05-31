<del>
## Public record of the method

This repository documents the development history of a stylized facial shadowing approach in Unreal Engine.

### Summary
This method suppresses unwanted facial self-occlusion while preserving artistically useful hair shadow on the face.

It consists of two parts:

1. **Facial self-occlusion suppression**  
   Unreal Engine's VSM-based transmission simulation is used to suppress unwanted self-occlusion near the face.

2. **Hair occlusion restoration**  
   Since the suppression step also weakens or removes hair occlusion on the face, hair occlusion is captured separately, blurred, and then applied through the **Face Material Opacity** to reconstruct stylized hair shadowing on the face.

### Development history
- **Since March 2025**  
  This project has used Unreal Engine's VSM-based transmission simulation to suppress facial self-occlusion near the face.

- **Since January 2026**  
  This project has used the full two-part method:
  - suppressing facial self-occlusion with Unreal Engine's VSM-based transmission simulation
  - restoring the lost hair occlusion through separate capture, blur, and application to the **Face Material Opacity**

- The public repository record for the January 2026 stage begins from commit `079084f8fa46bf5cdc9f03c1316dd37ecb133d9b`, dated **January 22, 2026 (+0900)**.

### Note
To the best of my knowledge, this repository is the first public documentation of this specific approach in Unreal Engine:
suppressing facial self-occlusion with VSM-based transmission simulation while reconstructing lost hair occlusion separately for stylized facial shadow control.
</del>
