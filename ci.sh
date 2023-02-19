#!/bin/bash
# Clone the framework repo
cpus=$(grep -c processor /proc/cpuinfo) ## get the cpu threads for maximum performance when compiling
echo -e "\x1B[32mCopiling with ${cpus} compute jobs!\033[0m"

git clone https://github.com/MadLadSquad/UntitledImGuiFramework.git --recursive
cd UntitledImGuiFramework/ || exit  # Enter the framework directory
./install.sh ci                     # Install the UVKBuildTool
cd ../ || exit                      # Go back to the project directory

# Even though normal projects are installed under Framework/Projects/ nothing really stops us from changing that
# directory to the current setup since we only need the symlinks to be there.
# Symlink the Framework and UVKBuildTool
ln -rs UntitledImGuiFramework/Framework Framework 2> /dev/null || cp UntitledImGuiFramework/Framework . -r 2> /dev/null
ln -rs UntitledImGuiFramework/UVKBuildTool UVKBuildTool 2> /dev/null || cp UntitledImGuiFramework/UVKBuildTool . -r 2> /dev/null

mkdir Generated/ || exit

# Generate the generated files for the project
cd UntitledImGuiFramework/UVKBuildTool/build || exit
./UVKBuildTool.exe --generate ../../../ || ./UVKBuildTool --generate ../../../ || exit
cd ../../../

cd ThirdParty/libavif/ext || exit
./dav1d.cmd || exit
cd ../../../ || exit

# Build the project
mkdir build || exit
cd build || exit
cmake ..
MSBuild.exe UntitledImageViewer.sln -property:Configuration=Release -property:Platform=x64 -property:maxCpuCount="${cpus}" || make -j "${cpus}" || exit
