cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES C)

# Флаги компиляции
set(C_FLAGS -std=c11 -Wall -Wextra -Wpedantic -Werror)

# --- Либратория ---
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS source/*.c)
if(SRC_FILES)
    add_library(my_lib ${SRC_FILES})
    target_include_directories(my_lib PUBLIC include)
    target_compile_options(my_lib PRIVATE ${C_FLAGS})
endif()

# --- Исполняемый main ---
add_executable(main main.c)
if(SRC_FILES)
    target_link_libraries(main PRIVATE my_lib)
endif()
target_compile_options(main PRIVATE ${C_FLAGS})

# --- Исполняемые тесты ---
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS tests/*.c)
if(TEST_FILES)
    add_executable(tests ${TEST_FILES})
    if(SRC_FILES)
        target_link_libraries(tests PRIVATE my_lib)
    endif()
    target_compile_options(tests PRIVATE ${C_FLAGS})
endif()
