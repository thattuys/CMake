if(USE_STEAMWORKS)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE
            USE_STEAMWORKS
    )

    # because of the pragma commit lib in Steamworks.h
    target_link_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()