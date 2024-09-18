cmake_minimum_required(VERSION 3.28)
project(AnimalShelter C)

set(CMAKE_C_STANDARD 23)

include_directories(product)
include_directories(test)
include_directories(shared)
include_directories(Unity)

add_executable(
        AnimalShelter
        product/main.c
        product/terminal_io.c
        shared/administration.c
        shared/file_element.c
        test/administration_test.c
        test/file_element_test.c
        test/main.c
        Unity/unity.c
        Unity/unity_test_module.c
)