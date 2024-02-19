target_sources(${PROJECT_NAME}
    PRIVATE
        UltraEngine.cpp
        project.rc
        main.cpp
)

add_subdirectory(Components)

if (USE_STEAMWORKS)
    add_subdirectory(Steamworks)
endif()