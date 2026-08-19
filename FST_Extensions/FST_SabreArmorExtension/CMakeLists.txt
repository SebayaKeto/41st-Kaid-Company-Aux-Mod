cmake_minimum_required(VERSION 3.21)

project(FST_SabreArmorExtension VERSION 1.0.0 LANGUAGES CXX)

add_library(FST_SabreArmorExtension SHARED src/SabreArmorExtension.cpp)

target_compile_features(FST_SabreArmorExtension PRIVATE cxx_std_17)
target_compile_definitions(FST_SabreArmorExtension PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)

if(MSVC)
    target_compile_options(FST_SabreArmorExtension PRIVATE /W4 /permissive- /EHsc)
endif()

set_target_properties(FST_SabreArmorExtension PROPERTIES
    OUTPUT_NAME "FST_SabreArmorExtension"
    PREFIX ""
)