cmake_minimum_required(VERSION 3.22)

#-------------------------------------------------------------------------------
#   vcpkg setup
#-------------------------------------------------------------------------------

if (NOT DEFINED VCPKG_ROOT)
    if (WIN32)
        set(VCPKG_ROOT "$ENV{userprofile}/vcpkg")
    else()
        set(VCPKG_ROOT "$ENV{HOME}/vcpkg")
    endif()
endif()

if (EXISTS "${VCPKG_ROOT}")
    set(VCPKG_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

    if (EXISTS "${VCPKG_TOOLCHAIN_FILE}")
        set(CMAKE_TOOLCHAIN_FILE "${VCPKG_TOOLCHAIN_FILE}" CACHE STRING "")
        message("-- Using vcpkg")
    endif()
endif()

#-------------------------------------------------------------------------------
#   project setup
#-------------------------------------------------------------------------------

set(target_name timer)

project(${target_name} CXX)

find_package(wxWidgets CONFIG REQUIRED)

#-------------------------------------------------------------------------------
#   target setup
#-------------------------------------------------------------------------------

add_executable(${target_name})

target_sources(${target_name} PRIVATE
    src/main.cpp
    src/TimerFrame.h
    src/TimerFrame.cpp
    src/TimerFrameBase.h
    src/TimerFrameBase.cpp
)

target_include_directories(${target_name} PRIVATE
    src
)

target_link_libraries(${target_name} PRIVATE
    wx::core
)

target_compile_features(${target_name} PRIVATE
    cxx_std_17
)

if (WIN32)
    set_target_properties(${target_name} PROPERTIES
        WIN32_EXECUTABLE TRUE
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
endif()
