# ![he2](https://user-images.githubusercontent.com/34447743/121752164-da28ff80-cb0f-11eb-9172-3b678d40b3a5.png)Hoopoe-Engine
##### <h2>Content</h2>
[Introduction](#introduction)<br/>
[Requirements](#requirements)<br/>
[Building](#building)<br/>
  - [Builder flags](#builder-flags)
  - [Cmake flags](#cmake-flags)

<a name="introduction"><h1>Introduction</h1></a>
Hoopoe engine is designed to create a simple simulated world.
<a name="requirements"><h1>Requirements</h1></a>

```no-highlight
sudo apt-get install build-essential cmake unzip libsdl2-dev
```

<a name="building"><h1>Building</h1></a>

```no-highlight
bash builder.sh
```
<a name="builder-flags"><h3>Builder flags</h3></a>
<code>--engine</code> or <code>-e</code> - build engine only.<br/>
<code>--sandbox</code> or <code>-s</code> - build sandbox only.<br/>
<code>--update-tests</code> or <code>-u</code> - update UTest resources.<br/>
<code>--default</code> or <code>-d</code> - build with default settings.<br/>
<a name="cmake-flags"><h3>Cmake flags</h3></a>
<code>-DUTEST=bool</code> - build with the unit-tests<br/>
<code>-DSANDBOX_ONLY=bool</code> - compiling only Sandbox (only for /Sandbox/CMakeLists.txt)<br/>

