-- premake5.lua
workspace "Poneros"
   configurations { "Debug", "Release" }

project "Poneros"
   kind "ConsoleApp"
   language "C++"
   targetdir "build/%{cfg.buildcfg}"

   files { "**.h", "**.cpp", "**.c" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"