<h1 align="center">
<img src="https://github.com/VisualStudioEX3/Home/blob/master/pictures/div_games_studio/div2_logo/div2_logo.png" alt="DIV Games Studio 2 logo" width="512" />
<br>
DIV2 Framework</h1>
<h6 align="center">© Visual Studio EX3, José Miguel Sánchez Fernández - 2020 - 2022</h6>
<h2 align="center">Collection of DLLs for DIV Games Studio 2</h2>

[![GitHub](https://img.shields.io/github/license/VisualStudioEX3/div2-framework?color=yellow)](https://opensource.org/licenses/MIT)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/VisualStudioEX3/div2-framework?color=green)](https://github.com/VisualStudioEX3/div2-framework/releases/)

> **Note**
> This repository is only for historical purpose. All this code is migrating to the new project, [DIV2 TLSA98 Engine](https://github.com/VisualStudioEX3/div2-tlsa98-engine).

# Introduction

A little collection of DLLs to extend the **DIV Games Studio 2** features and language, designed intially for the [StarFighter](https://github.com/VisualStudioEX3/StarFighter) project but are ready to use in any **DIV Games Studio 2** project.

### Ready to use:
- **DEBUG.DLL**: Adds a print command to print text strings in screen, over the all game render, like on the old BASIC interpreters.
- **MATH.DLL**: Extra math functions.
- **RECT.DLL**: Functions to make basic operations with rectangles.
- **STRING.DLL**: Extra functions to manipulate strings.
- **LOGGER.DLL**: Basic logger file system.
- **PROCESS.DLL**: Functions to manage DIV processes.
- **TIMER.DLL**: Advanced timers.

### Unfinished:
- **INPUTMAN.DLL**: Advanced input manager based on maps with actions and virtual axis definitions.
- **INIFILE.DLL**: Parser to manage INI files.

All source code is documented in formatted code comments. Check header files.

> **Note**
> These files are the second iteration of development. A previous version of this collection of DLLs, source code and binaries, are found in the **StarFighter** repository: https://github.com/VisualStudioEX3/StarFighter/tree/develop/DLL

> **Warning**
> This DLLs are designed to work with the original published **DIV Games Studio 2** version from 1998. Not guarantee to work in modern forks like [Div DX / DIV Games Studio 3](https://github.com/DIVGAMES/DIV-Games-Studio) or [DIV Games Studio 2.02](https://github.com/vii1/DIV) because they are not tested on them, and not are suported on forks like [Fenix Project](https://web.archive.org/web/20071012230137/http://fenix.divsite.net/) (and his variants), CDiv, [Div GO](https://www.divgo.net/), [Gemix Studio](http://www.gemixstudio.com/), [Bennu GD](https://www.bennugd.org/), or [PixTudio](https://pixtudio.org/).

# How to compile
This DLLs are writen in **ANSI C-89** using **Watcom C++ 10.6**. You can download it from [Archive.org](https://archive.org/details/Watcom_C_10.6) as abandoneware. 

> **Warning**
> Newer versions of **Watcom** or [Open Watcom](https://github.com/open-watcom/open-watcom-v2) fork are not supported or the compiled binaries are not compatible with the expected by **DIV Games Studio 2** runtime.

Each DLL project has a file named `MAKE.BAT`. Run it to compile the DLL. Also, in the root folder, you have another `MAKE.BAT` that allows you to compile each DLL and perform a cleanup and copy the binary to the **DIV Games Studio 2** folder (check the content file to get more information to how setup properly):

`MAKE.BAT <folder name>`

# How to setup Watcom to compile DIV Games Studio DLLs
> **Note**
> Watcom C++ 10.6 is supported on current Windows versions (at least on Windows 10).

- Install **Watcom C++ 10.6** using the default setup profile (this ensure that install all required dependencies).

> **Warning**
> When the installer ask you to overwrite Windows system files, click on **No** to avoid overwrite current ones with older versions that might broken your system.

- When is installed, go to the `binw` folder in your **Watcom** folder.
- Looking for the `wlsystem.lnk` file and open it in a text editor for edit.
- Add these lines at the end (are the content of the `DIV_DLL.LNK` file):

```
system begin div_dll
    option osname='DIV DLL'
    libpath %WATCOM%\lib386 
    libpath %WATCOM%\lib386\dos
    format windows nt dll ^
end
```

> **Warning**
> If you try to compile from **Windows**, check if `wcl386` command is recognized by the **Windows Command Prompt** or **PowerShell** console. If not, add the `C:\<WATCOM FOLDER PATH>\BINW` path to the Windows environment variables.

# What is DIV Games Studio?

###### Wikipedia page: https://es.wikipedia.org/wiki/DIV_Games_Studio

Maybe was one of the first game engines for the public. **DIV Games Studio** is a complete solution to develop games for **MS-DOS** and published in 1997 (DIV1) and 1998 (DIV2). 

Is a full windows graphic environment with tools for creation and editing 2D graphics (with a complete drawing suit), particle FX, character animations, font character sets, sounds effects and a complete language programming with a syntax between **Pascal** and **C**, including an integrated debugger and a full complete documentation with a lot of tutorials and samples. 

This engine allow to develop common 2D games with a full of advanced graphic features, and pseudo 3D games using the [Mode7](https://en.wikipedia.org/wiki/Mode_7) and later, with DIV2, the Mode8 (3D feature like the original Doom).

**DIV Games Studio** was very popular at the end of ninetys and early 2000. Was the start point of an entire generation of game developers of nowdays. During the years, the community was develop a multiple forks like [Fenix Project](https://web.archive.org/web/20071012230137/http://fenix.divsite.net/) (with multiple flavours), CDiv, [Div GO](https://www.divgo.net/), [Gemix Studio](http://www.gemixstudio.com/), [Bennu GD](https://www.bennugd.org/), or [PixTudio](https://pixtudio.org/).

Currently exists 2 projects to bring it to live again:
* [Div DX / DIV Games Studio 3](https://github.com/DIVGAMES/DIV-Games-Studio) - A port of DIV Games Studio 2 to modern systems (running on Windows, Linux and Mac natively) but keeping the all original features of DIV Games Studio 2. One of the interested features, including the fix of most of the existing bugs on original DIV2, is the posibility of export the games natively to multiple systems, including Android, HTML5 and some consoles. This project has still in beta and seems to be abandoned since 2016.
* [DIV Games Studio 2.02](https://github.com/vii1/DIV) - A reconstruction and fixing of the original DIV Games Studio 2 (v 2.01) for MS-DOS. This is an active project today where the developers want to fix the multiple bugs in the language programming and engine, improve the tools, and, maybe in a future, create a version for Amiga OS.

**DIV Games Studio** is fully functional on [DOSBox](https://www.dosbox.com/). You can download **DIV Games Studio 2** ISO from [Archive.org](https://archive.org/details/div-games-studio-2) as abandoneware.

![DIV Games Studio 2 screenshots](https://github.com/VisualStudioEX3/Home/blob/master/pictures/div_games_studio/div2_screen_mosaic.png)
