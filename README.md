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
