
# Corylium
Corylium is a game engine project that I'm working on in order to gain experience in developing ambitious software engineering projects.
***
## Project Setup
The project is currently only available on Windows devices. There are some prerequisites that will need to be installed before getting started: [Visual Studio 2022](https://visualstudio.microsoft.com/vs/community/), [Python](https://www.python.org/downloads/), enabling [wsl2](https://learn.microsoft.com/en-us/windows/wsl/install), [Git](https://git-scm.com/downloads).

<ins>**1. Start by cloning the repository recursively**</ins> in order to include git submodule dependencies:\
`git clone --recursive https://github.com/SplitShade/Corylium`

If you've already cloned the repo without using the recursive flag, you can add the submodules by running: `git submodule update --init`

<ins>**2. Run the Setup script**</ins> in order to download binary dependencies, for Windows it is located in `scripts/SetupWindows.bat`

<ins>**3. Open Corylium.sln using Visual Studio**</ins> \
Right-click on " Solution 'Corylium' " in the Solution Explorer tab and go to Properties, Common Properties->Startup Project and make sure the selection is Single Startup Project - Sandbox. This will enable you to quickly run the Project by pressing F5 or clicking on Local Windows Debugger.
When building the solution for the first time, you might get an error in the output that can be ignored and will not persist.
