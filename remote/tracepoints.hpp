// Set up LTTNG tracepoints for certain parallel algorithms

// this is a Linux-only facility AFAICT
#ifdef __linux__

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER TPR

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./tracepoints.hpp"

#if !defined(_TP_REMOTE_HPP) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TP_REMOTE_HPP

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    TPR,
    remote_event,
    TP_ARGS(),
    TP_FIELDS()
)


#endif // !defined(_TP_REMOTE_HPP) || ...

#include <lttng/tracepoint-event.h>

#endif // __linux__
