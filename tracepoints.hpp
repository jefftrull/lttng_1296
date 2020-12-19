#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER TPL

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./tracepoints.hpp"

#if !defined(_TP_LOCAL_HPP) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TP_LOCAL_HPP

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    TPL,
    local_event,
    TP_ARGS(),
    TP_FIELDS()
)

#endif // _TP_LOCAL_HPP

#include <lttng/tracepoint-event.h>
