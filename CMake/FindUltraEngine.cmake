include(FindPackageHandleStandardArgs)

find_path(UltraEngine_INCLUDE_DIR
    NAMES       UltraEngine.h
    PATHS       $ENV{ULTRAENGINE}/Include
)

find_library(UltraEngine_LIBRARY_DEBUG
    NAMES       UltraEngine_d
    PATHS       $ENV{ULTRAENGINE}/Library
)

find_library(UltraEngine_LIBRARY_RELEASE
    NAMES       UltraEngine
    PATHS       $ENV{ULTRAENGINE}/Library
)

find_package_handle_standard_args(UltraEngine
    FOUND_VAR 		UltraEngine_FOUND
    REQUIRED_VARS 	UltraEngine_INCLUDE_DIR
)

if (UltraEngine_FOUND)
    set(UltraEngine_INCLUDEDIRS
        ${UltraEngine_INCLUDE_DIR}
        ${UltraEngine_INCLUDE_DIR}/Libraries/zlib 
        ${UltraEngine_INCLUDE_DIR}/Libraries/Box2D
        ${UltraEngine_INCLUDE_DIR}/Libraries/freetype/include
        ${UltraEngine_INCLUDE_DIR}/Libraries/OpenAL/include
        ${UltraEngine_INCLUDE_DIR}/Libraries/RecastNavigation/RecastDemo/Include
        ${UltraEngine_INCLUDE_DIR}/Libraries/RecastNavigation/DetourCrowd/Include
        ${UltraEngine_INCLUDE_DIR}/Libraries/RecastNavigation/DetourTileCache/Include
        ${UltraEngine_INCLUDE_DIR}/Libraries/RecastNavigation/DebugUtils/Include
        ${UltraEngine_INCLUDE_DIR}/Libraries/RecastNavigation/Recast/Include
        ${UltraEngine_INCLUDE_DIR}/Libraries/RecastNavigation/Detour/Include
        ${UltraEngine_INCLUDE_DIR}/Libraries/sol3/include
        ${UltraEngine_INCLUDE_DIR}/Libraries/Lua/src
        ${UltraEngine_INCLUDE_DIR}/Libraries/enet/include
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dTinyxml
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dExtensions
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dIkSolver
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dJoints
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dModels/dVehicle
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dModels/dCharacter
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dModels
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dNewton/dParticles
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dNewton
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dCore
        ${UltraEngine_INCLUDE_DIR}/Libraries/newton/sdk/dCollision
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dVehicle/dMultiBodyVehicle
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dVehicle
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dMath
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dgCore
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dgNewton
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dAnimation
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dgTimeTracker
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dContainers
        ${UltraEngine_INCLUDE_DIR}/Libraries/NewtonDynamics/sdk/dCustomJoints
    )
endif()

mark_as_advanced(UltraEngine_INCLUDE_DIR UltraEngine_LIBRARY_DEBUG UltraEngine_LIBRARY_RELEASE)