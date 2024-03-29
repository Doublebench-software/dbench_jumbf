# CMakeList.txt : CMake project for dbench_jumbf, include source and define
# project specific logic here.
#

set(DBENCH_JUMBF_MAJOR_VERSION 2)
set(DBENCH_JUMBF_MINOR_VERSION 0)
set(DBENCH_JUMBF_PATCH_VERSION 0)
set(JPEG_JUMBF_LIBRARY_VERSION
    "${DBENCH_JUMBF_MAJOR_VERSION}.${DBENCH_JUMBF_MINOR_VERSION}.${DBENCH_JUMBF_PATCH_VERSION}")


# Add source to this project's executable.
file(GLOB SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "include/*.h")
add_library(dbench_jumbf 
	${SRCS}
	${HDRS}
)

target_include_directories(dbench_jumbf PUBLIC "${CMAKE_SOURCE_DIR}/dbench_jumbf/include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET dbench_jumbf PROPERTY CXX_STANDARD 14)
endif()

# TODO: Add tests and install targets if needed.
