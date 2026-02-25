file(GLOB_RECURSE SIF_SRC "src/*.cpp")
add_library(sif_lib STATIC ${SIF_SRC})

target_include_directories(sif_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${JSON_DIR}
)

# configuration Asset_GUID_Assignment
set(ASSET_GUID_ASSIGNMENT "Asset_GUID_Assignment")
add_executable(${ASSET_GUID_ASSIGNMENT} ${CMAKE_CURRENT_SOURCE_DIR}/src/Asset_GUID_Assignment.cpp)
target_link_libraries(${ASSET_GUID_ASSIGNMENT} PRIVATE sif_lib)

# configuration Asset_Reference_Serialization
set(ASSET_REFERENCE_SERIALIZATION "Asset_Reference_Serialization")
add_executable(${ASSET_REFERENCE_SERIALIZATION} ${CMAKE_CURRENT_SOURCE_DIR}/src/Asset_Reference_Serialization.cpp)
target_link_libraries(${ASSET_REFERENCE_SERIALIZATION} PRIVATE sif_lib)