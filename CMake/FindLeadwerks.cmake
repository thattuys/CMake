include(FindPackageHandleStandardArgs)

find_path(Leadwerks_INCLUDE_DIR
    NAMES       Leadwerks.h
    PATHS       $ENV{LEADWERKS}/Include
)

find_library(Leadwerks_LIBRARY_DEBUG
    #NAMES       Leadwerks_d
    NAMES       UltraEngine_d
    PATHS       $ENV{LEADWERKS}/Library
)

find_library(Leadwerks_LIBRARY_RELEASE
    #NAMES       Leadwerks
    NAMES       UltraEngine
    PATHS       $ENV{LEADWERKS}/Library
)

find_package_handle_standard_args(Leadwerks
    FOUND_VAR 		Leadwerks_FOUND
    REQUIRED_VARS 	Leadwerks_INCLUDE_DIR
)

if (Leadwerks_FOUND)
    set(Leadwerks_INCLUDEDIRS
        ${Leadwerks_INCLUDE_DIR}
        ${Leadwerks_INCLUDE_DIR}/Libraries/Draco/src
        ${Leadwerks_INCLUDE_DIR}/Libraries/libvorbis/include
        ${Leadwerks_INCLUDE_DIR}/Libraries/libogg/include
        ${Leadwerks_INCLUDE_DIR}/Libraries/zlib
        ${Leadwerks_INCLUDE_DIR}/Libraries/Box2D
        ${Leadwerks_INCLUDE_DIR}/Libraries/freetype/include
        ${Leadwerks_INCLUDE_DIR}/Libraries/OpenAL/include
        ${Leadwerks_INCLUDE_DIR}/Libraries/RecastNavigation/RecastDemo/Include
        ${Leadwerks_INCLUDE_DIR}/Libraries/RecastNavigation/DetourCrowd/Include
        ${Leadwerks_INCLUDE_DIR}/Libraries/RecastNavigation/DetourTileCache/Include
        ${Leadwerks_INCLUDE_DIR}/Libraries/RecastNavigation/DebugUtils/Include
        ${Leadwerks_INCLUDE_DIR}/Libraries/RecastNavigation/Recast/Include
        ${Leadwerks_INCLUDE_DIR}/Libraries/RecastNavigation/Detour/Include
        ${Leadwerks_INCLUDE_DIR}/Libraries/sol3/include
        ${Leadwerks_INCLUDE_DIR}/Libraries/Lua/src
        ${Leadwerks_INCLUDE_DIR}/Libraries/enet/include
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dTinyxml
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dExtensions
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dIkSolver
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dJoints
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dModels/dVehicle
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dModels/dCharacter
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dModels
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dParticles
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dNewton
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dCore
        ${Leadwerks_INCLUDE_DIR}/Libraries/newton/sdk/dCollision
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dVehicle/dMultiBodyVehicle
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dVehicle
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dMath
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dgCore
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dgNewton
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dAnimation
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dgTimeTracker
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dContainers
        ${Leadwerks_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dCustomJoints
    )
endif()

mark_as_advanced(Leadwerks_INCLUDE_DIR Leadwerks_LIBRARY_DEBUG Leadwerks_LIBRARY_RELEASE)