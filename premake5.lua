configurations {
	"Debug",
	"Release",
}

platforms {
	"Win32",
	"Win64",
}

defines {
	"GUID_WINDOWS"
}

flags {
	"FatalWarnings",
	"MultiProcessorCompile",
	"NoPCH",
	"Unicode",
}

filter "configurations:Debug"
	defines { "DEBUG" }
	flags { "Symbols" }
	targetsuffix "-d"

filter "configurations:Release"
	defines { "NDEBUG" }
	optimize "On"

filter { "platforms:Win32" }
	architecture "x32"
	libdirs { "dep/lib" }
	system "Windows"
	targetdir "bin"

filter { "platforms:Win64" }
	architecture "x64"
	libdirs { "dep/lib64" }
	system "Windows"
	targetdir "bin64"

workspace "Engine"
	language "C++"
	location "build"

project "2DFight"
	files {
		"code/**"
	}
	includedirs {
		"code",
		"dep/include",
	}
	location "build/2DFight"
	kind "ConsoleApp"
	rtti "Off"
	vpaths {
		-- engine = "*"
	}