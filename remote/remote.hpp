#include "tracepoints.hpp"

void
// explicitly export this shared symbol
__attribute__((visibility("default")))
foo();

// bar() will be used by main.cpp
template<typename T>
void bar() { tracepoint(TPR, remote_event); }


