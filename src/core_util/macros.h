/// @file core_util/macros.h
/// @brief Macros for various purposes.
#pragma once

/// Expect macro for branch prediction.
#define LIKELY(x) __builtin_expect(!!(x), 1)

/// Expect-not-taken macro for branch prediction.
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

/// Unreachable macro for indicating unreachable code.
#define UNREACHABLE() __builtin_unreachable()

/// Assert macro for debugging.
#ifdef NDEBUG
#define ASSERT(x) ((void)0)
#else
#define ASSERT(x)                                                              \
  do {                                                                         \
    if (UNLIKELY(!(x))) {                                                      \
      fprintf(stderr, "Assertion failed: %s, file %s, line %d\n", #x,          \
              __FILE__, __LINE__);                                             \
      UNREACHABLE();                                                           \
    }                                                                          \
  } while (0)
#endif

/// Assume macro for compiler hints.
#define ASSUME(x) __builtin_assume(!!(x))

/// Array size macro for determining the size of an array.
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
