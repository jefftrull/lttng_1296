add_library( remote SHARED remote.cpp tracepoints.cpp )
# actual test case uses default hidden visibility for all symbols
target_compile_options( remote PRIVATE -fvisibility=hidden )
target_link_options( remote PRIVATE -Wl,-fvisibility=hidden )
target_include_directories( remote PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
