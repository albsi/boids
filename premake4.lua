solution "boids"
   configurations { "debug", "release" }
   language "C++"
   buildoptions "-std=c++11"
 
   includedirs {
      "incl"
   }

   configuration "debug"
      flags { "Symbols" }
   
   project "boids"
      kind "ConsoleApp"

      files {
         "src/**.cpp"
      }