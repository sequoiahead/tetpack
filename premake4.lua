DIR_TARGET = "target"  
DIR_BIN_DEBUG = DIR_TARGET .. "/debug/bin" 
DIR_BIN_RELEASE = DIR_TARGET .. "/release/bin" 
DIR_LIB_DEBUG = DIR_TARGET .. "/debug/lib" 
DIR_LIB_RELEASE = DIR_TARGET .. "/release/lib" 

solution "tetpack"
	configurations { "debug", "release" }
	flags { "FatalWarnings", "ExtraWarnings", "NoRTTI" }
	location (DIR_TARGET)
	
	configuration { "linux" , "gmake" }
		buildoptions { "-std=c++11 -pedantic" } 
	
	configuration { "debug" }
		defines { "_DEBUG" }
		flags { "Symbols" }
		libdirs { (DIR_LIB_DEBUG .. "/**") }
		targetdir (DIR_BIN_DEBUG)
		
	configuration { "release" }
		defines { "_RELEASE" }
		flags { "OptimizeSpeed" }
		libdirs { (DIR_LIB_RELEASE .. "/**") }
		targetdir (DIR_BIN_RELEASE)
		
	project "tetpack"
		kind "WindowedApp"
		language "C++"
		targetname "tetpack"
		includedirs { "src/", "src/main/" }
		files { "src/main/**.cpp" }
		links { "game", "SDL2", "SDL2_image" }
		
	project "game" 
		kind "StaticLib"
		language "C++"
		includedirs { "src/" }
		files { "src/libgame/**.cpp" }
		links { "SDL2" }
		
	configuration { "debug" }
		targetdir (DIR_LIB_DEBUG)
		
	configuration { "release" }
		targetdir (DIR_LIB_RELEASE)
	
	project "test_libgame"
		kind "ConsoleApp"
		language "C++"
		includedirs { "src/" }
		files { "src/test/**.cpp" }
		links { "game", "cppunit", "SDL2" }
		
if _ACTION == "clean" then
	os.rmdir(DIR_TARGET)
end
