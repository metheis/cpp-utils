/// @file credit_card_validator.cc

#include "credit_card_validator.h"

#include <algorithm>
#include <cctype>
#include <iostream>

// Validates if the given credit card number is valid using the Luhn algorithm
bool CreditCardValidator::isValid(const FixedString32 &cardNumber) {
  FixedString32 sanitized = sanitizeInput(cardNumber);
  if (cardNumber.size() < 13 || cardNumber.size() > 19) {
    return false; // Length check
  }
  std::cout << "Sanitized input: " << sanitized.c_str() << std::endl;
  return luhnCheck(cardNumber);
}

// Removes non-digit characters from the input
FixedString32 CreditCardValidator::sanitizeInput(const FixedString32 &input) {
  FixedString32 sanitized;
  for (const char c : input) {
    if (std::isdigit(c)) {
      std::cout << "Processing digit: " << c << std::endl;
      sanitized += c;
    }
  }
  return sanitized;
}

// Implements the Luhn algorithm to validate the credit card number
bool CreditCardValidator::luhnCheck(const FixedString32 &cardNumber) {
  int sum = 0;
  bool doubleDigit = false;

  for (const char c : cardNumber) {
    int digit = c - '0';
    std::cout << "Processing digit: " << digit << std::endl;
    if (doubleDigit) {
      digit *= 2;
      if (digit > 9) {
        digit -= 9;
      }
    }
    sum += digit;
    doubleDigit = !doubleDigit;
  }

  std::cout << "Luhn sum: " << sum << std::endl;

  return (sum % 10) == 0;
}
