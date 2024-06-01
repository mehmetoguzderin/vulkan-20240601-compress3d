cmake_minimum_required(
    VERSION 3.20)
project(
    vulkan-20240601-compress3d CXX)

set(
    CMAKE_CXX_STANDARD 20)
set(
    CMAKE_CXX_STANDARD_REQUIRED ON)
set(
    CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
    vulkan-20240601-compress3d main.cpp)

target_compile_definitions(
    vulkan-20240601-compress3d PRIVATE VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL=1)

target_include_directories(
    vulkan-20240601-compress3d PRIVATE Vulkan-Headers/include)
