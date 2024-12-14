@echo OFF

call "C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Auxiliary\Build\vcvars64.bat"

set includes=/Isrc /I".\include"
set links=/link /LIBPATH:".\lib" glfw3.lib user32.lib vcruntime.lib msvcrt.lib shell32.lib gdi32.lib

cl.exe /Fo:"./" /Fe:"./build/poneros.exe" %includes% %defines% ./src/main.cpp %links% /NODEFAULTLIB:LIBCMT

