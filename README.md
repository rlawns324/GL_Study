### OpenGL Study  

## Development Environments  
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
     <img src="img/_1.png" width="500">  
  - Go `File` -> `Project Settings...` -> Build System : `Legacy Build System`  
     <img src="img/_2.png" width="500">  
  - `Signing & Capabilities` -> `Hardened Runtime`(if it exists) -> Click `x` icon  
     <img src="img/_3.png" width="500">  
  - `General` -> `Frameworks and Libraries` -> Click `+`  
     <img src="img/_4.png" width="500">  
  - Search `OpenGL`, add `OpenGL.framework'  
     <img src="img/_5.png" width="500">  
  - Click `+` -> `Add Other..` -> `Add Files...` -> `Shift + Command + G` -> Go to the folder `/usr/local/Cellar/`  
     <img src="img/_6.png" width="500">       <img src="img/_7.png" width="500">  
     
  - `glew` -> `(Your Version, ex: 2.1.0_1)` -> `lib` -> `libGLEW.2.1.0.dylib` 
     <img src="img/_8.png" width="500">  
  - `glfw` -> `(Your Version, ex: 3.3.2)` -> `lib` -> `libglfw.3.3.dylib` 
     <img src="img/_9.png" width="500">  
  
  - Go `Build Settings`  
  - Search `Header Search Path`, add both   
  `/usr/local/Cellar/glfw/(Your ver)3.3.2/include/`  
  `/usr/local/Cellar/glew/(Your ver)2.1.0_1/include/`  
     <img src="img/_10.png" width="500">  

### 3. locate shader source 
  - Products -> Right Click `GL_Study`(exec file) -> `Show in Finder`  
  - copy `shader.vert`, `shader.frag` to above exec directory  
    <img src="img/_11.png" width="500">  
  - Build & Run  
    <img src="img/_12.png" width="500">  
  
[**Reference**](https://blog.naver.com/ross1573/221460518505)  

</div>
</details>  


<details>  
<summary> Windows </summary>
<div markdown="1"> 

  - [OpenGL Setting for Windows](https://webnautes.tistory.com/1102)  
  
</div>
</details>  
