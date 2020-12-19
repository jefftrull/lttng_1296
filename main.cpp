#include <iostream>
#include <cstdio>

#define TRACEPOINT_DEFINE
#define TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#include "tracepoints.hpp"
#include "remote/remote.hpp"

int main()
{
    std::cout << "press enter to start" << std::endl;
    getchar();

    tracepoint(TPL, local_event);   // direct tracepoint, "our" provider
    bar<double>();                  // indirect tracepoint via "remote" provider
    foo();                          // also indirect
}
