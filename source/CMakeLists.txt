if(WIN32)
    set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
    set(LIBRARY_SDL2_DIR "${CMAKE_SOURCE_DIR}/libs/SDL2")

    # use bundled version to save ourselves a lot of trouble
    set(LINKER_LIBRARY "-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net")
    
    # copy dynamic libraries
    file(COPY 
            "${CMAKE_SOURCE_DIR}/bin/SDL2/SDL2.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/libjpeg-9.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/libpng16-16.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/libtiff-5.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/SDL2_image.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/zlib1.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/SDL2_net.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/SDL2_ttf.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/SDL2_mixer.dll"
            "${CMAKE_SOURCE_DIR}/bin/SDL2/libwebp-7.dll"
            DESTINATION ${CMAKE_BINARY_DIR})
else()
    # let FindSDL2.cmake figure out where it is on Mac/Linux
    # Put the FindSDL2.cmake in ./cmake and tell CMake to find it there
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

    set(SDL2MAIN_LIBRARY "")

    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    find_package(SDL2_mixer REQUIRED)
    find_package(SDL2_net REQUIRED)
endif()

# include SDL header files
include_directories(${INCLUDE_DIR})
link_directories(${LIBRARY_SDL2_DIR})

# load user source and header files
file(GLOB_RECURSE SOURCE_FILES "*.h" "*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})

# make assets directory in build
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)

# copy game assets into build/assets directory
file(COPY
       "${CMAKE_SOURCE_DIR}/assets/"
       DESTINATION ${CMAKE_BINARY_DIR}/assets)

# SDL2MAIN_LIBRARY is needed for Windows specific main function.
target_link_libraries(${PROJECT_NAME} ${LINKER_LIBRARY})