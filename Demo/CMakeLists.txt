cmake_minimum_required(VERSION 3.2)
set(PROJECT_NAME Demo)
set(PROJECT_VERSION 1.0)
project(${PROJECT_NAME} LANGUAGES CXX)

# 此处配合 VMSVC 的 UTF8-BOM 插件，达到跨平台
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message("---using Clang---")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message("---using GCC---")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    message("---using Intel C++---")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message("---using Visual Studio C++---")
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(SOURCES
    main.cpp
    exwidget.cpp
    exwidget.h)

if (APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})
else()
    add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

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
