cmake_minimum_required( VERSION 3.12 )

project( lttng_1296 )

# create a compilation database for clangd etc.
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set( CMAKE_CXX_STANDARD 17 )

// "remote" library (a proxy for the shared library I'm using in the real code)
add_subdirectory( remote )

// "local" library, standing in for my main application code's tracepoints
add_library( tp_local SHARED tracepoints.cpp )
target_include_directories( tp_local PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )

// when this is run only the "remote" events can be traced:
add_executable( ltt main.cpp )
target_link_libraries( ltt remote tp_local lttng-ust dl )
