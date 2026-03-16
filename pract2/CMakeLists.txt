
cmake_minimum_required(VERSION 3.10)
project(MyProject C)
include_directories(include)                     
add_executable(main src/main.c)
add_library(static STATIC src/samolet.c)
add_library(shared SHARED src/samolet.c)
target_link_libraries(main static)
set_target_properties(static shared PROPERTIES EXCLUDE_FROM_ALL TRUE)
add_custom_target(build_static
    COMMAND ${CMAKE_COMMAND} --build . --target static
)

add_custom_target(build_shared
    COMMAND ${CMAKE_COMMAND} --build . --target shared
)
add_custom_target(run
    COMMAND ./main
    DEPENDS main
    COMMENT "Запуск ./main"
)