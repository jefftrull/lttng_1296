add_library( remote SHARED remote.cpp tracepoints.cpp )
target_include_directories( remote PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
