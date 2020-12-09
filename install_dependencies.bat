@echo off 
cd C:\dev\vcpkg

if NOT %ERRORLEVEL% == 0 (
	echo vcpkg folder not found. Please make sure it is installed.
	pause
	exit /b 0
)

vcpkg.exe install sdl2:x86-windows
vcpkg.exe install sdl2:x64-windows
vcpkg.exe install gtest:x86-windows
vcpkg.exe install gtest:x64-windows
vcpkg.exe install enet:x86-windows
vcpkg.exe install enet:x64-windows
vcpkg.exe install sdl2-mixer:x86-windows
vcpkg.exe install sdl2-mixer:x64-windows
vcpkg.exe install sdl2-image:x86-windows
vcpkg.exe install sdl2-image:x64-windows
vcpkg.exe install sdl2-ttf:x64-windows
vcpkg.exe install sdl2-ttf:x86-windows
vcpkg.exe install jsoncpp:x86-windows
vcpkg.exe install jsoncpp:x64-windows

if NOT %ERRORLEVEL% == 0 (
	echo Please make sure vcpkg is installed correctly.
	pause
	exit /b 0
) else (
	echo Dependencies successfully installed!
	pause
	exit /b 0
)