### Install Guide for CE OpenGL Study  
### Development Environments  
- OS : macOS Mojave 10.14.6     
- IDE : XCode 11.1  

<details>  
<summary> macOS </summary>
<div markdown="1"> 
  
## Setting  
### 0. Install Homebrew  
`$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
### 1. Install glfw, glew
`$ brew install glfw`    
`$ brew install glew`
### 2. XCode Project Setting
  - clone this repo, run XCode -> `File` -> `Open` -> Open `GL_Study.xcodeproj`  
     <img src="img/_1.jpeg" width="500">  
  - Go `File` -> `Project Settings...` -> Build System : `Legacy Build System`  
     <img src="img/_2.jpeg" width="500">  
  - `Signing & Capabilities` -> `Hardened Runtime`(if it exists) -> Click `x` icon  
     <img src="img/_3.jpeg" width="500">  
  - `General` -> `Frameworks and Libraries` -> Click `+`  
     <img src="img/_4.jpeg" width="500">  
  - Search `OpenGL`, add `OpenGL.framework'  
     <img src="img/_5.jpeg" width="500">  
  - Click `+` -> `Add Other..` -> `Add Files...` -> `Shift + Command + G` -> Go to the folder `/usr/local/Cellar/`  
     <img src="img/_6.jpeg" width="500">       <img src="img/_7.jpeg" width="500">  
     
  - `glew` -> `(Your Version, ex: 2.1.0_1)` -> `lib` -> `libGLEW.2.1.0.dylib` 
     <img src="img/_8.jpeg" width="500">  
  - `glfw` -> `(Your Version, ex: 3.3.2)` -> `lib` -> `libglfw.3.3.dylib` 
     <img src="img/_9.jpeg" width="500">  
  
  - Go `Build Settings`  
  - Search `Header Search Path`, add both   
  `/usr/local/Cellar/glfw/(Your ver)3.3.2/include/`  
  `/usr/local/Cellar/glew/(Your ver)2.1.0_1/include/`  
     <img src="img/_10.jpeg" width="500">  
  - Build & Run  
    <img src="img/_12.jpeg" width="500">  
    
### 3. Shader Macro  
  - `V_SHADER`와 `F_SHADER` 라는 macro를 통해 shader 파일들을 실행파일이 읽어 올 수 있습니다.  
  - `V_SHADER`와 `F_SHADER` 라는 macro를 통해 shader 파일들을 실행파일이 읽어 올 수 있습니다. 따라서 매 실행시마다 실행파일 경로 찾아서 복사해야하는 번거로움이 없어졌습니다.  
  - 만약 안된다면, `Build Settings` -> `preprocessor macros` 검색 -> `Debug`에다가
  `F_SHADER=\"${PROJECT_DIR}/GL_Study/shader.frag\"`  
  `V_SHADER=\"${PROJECT_DIR}/GL_Study/shader.vert\"` 을 추가해줍니다.(스샷 참고)
  <img src="img/_11.jpeg" width="500">  
    - 위와같이 매크로가 설정돼있기 때문에 shader파일명을 변경하거나, 매크로 변수명을 변경하면 그에따라 환경설정을 다시 해줘야 합니다.
    
  [**Reference**](https://blog.naver.com/ross1573/221460518505)  
  </div>
  </details>  
  
  <details>  
  <summary> Windows </summary>
  <div markdown="1">  
  
  - [OpenGL Setting for Windows](https://webnautes.tistory.com/1102)
  
  </div>
  </details>  
