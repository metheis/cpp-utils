/// @file credit_card_validator.h
/// @brief Credit Card Validator using the Luhn algorithm.
#pragma once

#include "core_util.h"

class CreditCardValidator {
public:
  /// Validates if the given credit card number is valid using the Luhn
  /// algorithm.
  static bool isValid(const FixedString32 &cardNumber);

private:
  /// Helper function to sanitize the input by removing non-digit characters.
  static FixedString32 sanitizeInput(const FixedString32 &input);

  /// Helper function to apply the Luhn algorithm.
  static bool luhnCheck(const FixedString32 &cardNumber);
};
