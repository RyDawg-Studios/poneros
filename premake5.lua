-- premake5.lua
workspace "Poneros"
   configurations { "Debug", "Release" }

project "Poneros"
   architecture "x64"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++latest"
   targetdir "build/%{cfg.buildcfg}"
   
   libdirs { "lib" }
   includedirs{"include/**", "include"} 

   files { "**.h", "**.cpp", "**.c" }
   links {"glfw3", "user32", "vcruntime", "shell32", "gdi32"}
   

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"