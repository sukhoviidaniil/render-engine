# Building the graphics library
file(GLOB_RECURSE VIEW_SRC "src/*.cpp")
add_library(rb_lib STATIC ${VIEW_SRC})
# Connecting headers
target_include_directories(rb_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${JSON_DIR}
)
target_link_libraries(rb_lib PUBLIC
        sfml-graphics
        sfml-window
        sfml-system
        infra_lib
)

