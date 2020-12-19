# LTTNG testcase for two dynamically linked providers

This is a relatively minimal testcase illustrating [a problem I'm having with LTTNG](https://bugs.lttng.org/issues/1296) where I can define two providers, both in shared libraries, and only the first provider's events can be enabled - though it seems LTTNG knows about both of them. In particular, the message of the form:

```
Provider "XXX" accepted, version 1.0 is compatible with...
```
appears only for the one of the providers when `LTTNG_UST_DEBUG=1` is set.

The problem appears to be related to linking - `ldd` shows that the final executable depends only on the provider shared library whose events are observable. Creating an artificial dependency on the other shared library (e.g. via `LD_PRELOAD` or adding a dependency in its code) works around the issue.
