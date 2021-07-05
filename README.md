# ![he2](https://user-images.githubusercontent.com/34447743/121752164-da28ff80-cb0f-11eb-9172-3b678d40b3a5.png)Hoopoe-Engine
##### <h2>Content</h2>
[Introduction](#introduction)<br/>
[Requirements](#requirements)<br/>
[Building](#building)<br/>
  - [Cmake flags](#building-flags)

<a name="introduction"><h1>Introduction</h1></a>
Hoopoe engine is designed to create a simple simulated world.
<a name="requirements"><h1>Requirements</h1></a>

```no-highlight
g++
make
CMake
unzip
SDL2
SQLite
```

<a name="building"><h1>Building</h1></a>

```no-highlight
bash build.sh
```
<code>HSandbox</code> - binary for run the application.<br/>
<code>HUTest</code> - binary for run the unit-tests.<br/>
<a name="building-flags"><h3>Cmake flags</h3></a>
<code>-DUTEST=bool</code> - build with the unit-tests<br/>
<code>-DSANDBOX_ONLY=bool</code> - compiling only Sandbox (only for /Sandbox/CMakeLists.txt)<br/>

