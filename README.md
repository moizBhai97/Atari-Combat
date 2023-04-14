# Atari-Combat
- Download zip and extract files
- Extract Glew and Glut folder separately
- Create new empty C++ project in Visual Studio Windows
- Make sure debugger is x86 and not x64
- Copy from Starter folder all cpp and all header and leader.txt files and paste it into project folder (If sln is not in same directry as project, select your project folder inside there will be sln and your project folder again, select it again and paste here)
- Add in project existing items and add the cpp and header files
- Go to project Properties-> C/C++ -> General -> Additional Include Directories -> edit -> new line -> add path of glew-1.11.0\include which is in glew and glut folder and press OK
- Repeat for path  freeglut\include
- Now in Properties -> Linker -> Input -> Additional Dependencies -> edit -> write freeglut.lib press enter and write glew32.lib and press OK
- Finally in Properties -> Linker -> General -> Additional Library Directories -> edit -> new line -> add path of glew-1.11.0\lib which is in glew and glut folder and press OK
- Repeat for path  freeglut\lib
- Copy glew32.dll and freeglut.dll from glew and gkut folder and copy them into project folder
- Now you should be able to build and run project without any errors
