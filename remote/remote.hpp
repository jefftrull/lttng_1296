#include "tracepoints.hpp"

void foo();

// bar() will be used by main.cpp
template<typename T>
void bar() { tracepoint(TPR, remote_event); }


