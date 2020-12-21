# LTTNG testcase for two dynamically linked providers

This is a relatively minimal testcase illustrating [a problem I'm having with LTTNG](https://bugs.lttng.org/issues/1296) where I can define two providers, both in shared libraries, and only the first provider's events can be enabled - though it seems LTTNG knows about both of them. In particular, the message of the form:

```
Provider "XXX" accepted, version 1.0 is compatible with...
```
appears only for the one of the providers when `LTTNG_UST_DEBUG=1` is set.

After some further analysis it seems that one of the providers' shared library is built with `-fvisibility=hidden`. Without a suitable `__attribute__((visibility="xxx"))` on the tracepoint-related symbols that provider's events won't be visible. This testcase reflects that situation.
