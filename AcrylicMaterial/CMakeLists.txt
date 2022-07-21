cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME AcrylicMaterial)
set(PROJECT_VERSION 1.0)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib)
set(BUILD_SHARED_LIBS ON)

set(SOURCES
    acrylicattribute.h
    acrylicmaterial.h
    acrylicmaterial.cpp
    dllmain.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(_src_root_path ${CMAKE_CURRENT_SOURCE_DIR})        # default root path curr path （CMakeList.txt）
file(GLOB_RECURSE _source_list LIST_DIRECTORIES false
    "${_src_root_path}/*.cpp"
    "${_src_root_path}/*.h")
source_group(TREE ${_src_root_path} FILES ${_source_list})

# msvc multicore compilation
if (WIN32 AND MSVC)
    option(USE_MP "use multiple" ON)
    option(ProjectConfig_Global_COMPILE_FLAGS_WITH_MP "Set The Global Option COMPILE_FLAGS /MP to target." ON)

    if(ProjectConfig_Global_COMPILE_FLAGS_WITH_MP OR USE_MP)
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    endif()

    set(VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        WIN32_LEAN_AND_MEAN                            # 仅仅包含常用的 API 的头文件，加快编译速度，效果明显
        _CRT_SECURE_NO_WARNINGS                        # 允许使用 strcpy，scanf等不安全的函数
        UNICODE
        _UNICODE)
endif()
