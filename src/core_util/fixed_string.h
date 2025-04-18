/// @file fixed_string.h
/// @brief Fixed-size string utility functions
#pragma once

#include "macros.h"
#include "types.h"

class FixedString32 {
public:
  /// Empty constructor.
  FixedString32() : length(0) { data[0] = '\0'; }

  /// Constructor with a string
  FixedString32(const char *str) { set(str); }

  /// Constructor with a string and length
  FixedString32(const char *str, U64 len) { set(str, len); }

  /// Copies a null-terminated string into the FixedString32
  void set(const char *str) {
    U64 len = 0;
    while (str[len] != '\0' && len < max_size_) {
      ++len;
    }
    if (UNLIKELY(len == max_size_)) {
      len = max_size_ - 1;
    }
    set(str, len);
  }

  /// Copies a string of length len into the FixedString32
  void set(const char *str, U64 len) {
    if (UNLIKELY(len > max_size_)) {
      len = max_size_;
    }
    __builtin_memset(data, 0, max_size_);
    __builtin_memcpy(data, str, len);
    length = len;
  }

  /// operator += for concatenation
  FixedString32 &operator+=(const char *str) {
    U64 len = 0;
    while (str[len] != '\0' && length + len < max_size_) {
      ++len;
    }
    if (UNLIKELY(length + len >= max_size_)) {
      len = max_size_ - length - 1;
    }
    __builtin_memcpy(data + length, str, len);
    length += len;
    data[length] = '\0';
    return *this;
  }

  /// operator += for concatenation with a character
  FixedString32 &operator+=(char c) {
    if (UNLIKELY(length >= max_size_ - 1)) {
      return *this;
    }
    data[length++] = c;
    data[length] = '\0';
    return *this;
  }

  /// Const pointer to the beginning of the string
  const char *begin() const { return data; }

  /// Const pointer to the end of the string
  const char *end() const { return data + length; }

  /// Returns a pointer to the underlying character array
  const char *c_str() const { return data; }

  /// Returns the length of the string
  U64 size() const { return length; }

  /// Returns the maximum size of the string
  static constexpr U64 max_size() { return max_size_; }

private:
  /// The maximum size of the string.
  static constexpr U64 max_size_ = 32;

  /// Fixed-size character array.
  char data[max_size_];

  /// Length of the string.
  U64 length;
};
