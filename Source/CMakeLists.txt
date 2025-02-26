target_sources(${PROJECT_NAME}
    PRIVATE
        UltraEngine.cpp
        project.rc
        main.cpp
        SelectDevice.cpp
        Encryption.cpp
        Leadwerks.cpp
)

add_subdirectory(Components)

if (USE_STEAMWORKS)
    add_subdirectory(Steamworks)
endif()