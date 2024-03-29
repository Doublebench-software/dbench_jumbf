# CMakeList.txt : CMake project for jumbf_lib, include source and define
# project specific logic here.
#
# executable
set( EXE_NAME dbench_jumbf_app )

# get source files
file( GLOB SRC_FILES "*.cpp" )

# get include files
file( GLOB INC_FILES "*.h" )

# Add source to this project's executable.
add_executable(${EXE_NAME} ${SRC_FILES} ${INC_FILES})

target_include_directories(${EXE_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/dbench_jumbf/include")
target_link_libraries(${EXE_NAME} dbench_jumbf)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${EXE_NAME} PROPERTY CXX_STANDARD 14)
endif()

# TODO: Add tests and install targets if needed.

