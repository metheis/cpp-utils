/// @file credit_card_validator_test.cc
/// @brief Unit tests for the Credit Card Validator using the Luhn algorithm.

#include "credit_card_validator.h"

#include <gtest/gtest.h>

/// Valid credit card numbers

TEST(CreditCardValidatorTest, ValidCardNumbers) {
  EXPECT_TRUE(CreditCardValidator::isValid("4539 1488 0343 6467")); // Visa
  EXPECT_TRUE(CreditCardValidator::isValid("4532015112830366")); // Visa
  EXPECT_TRUE(CreditCardValidator::isValid("6011-1111-1111-1117")); // Discover
  EXPECT_TRUE(CreditCardValidator::isValid("3714 4963 5398 431")); // American Express
}

/// Invalid credit card numbers
TEST(CreditCardValidatorTest, InvalidCardNumbers) {
  EXPECT_FALSE(CreditCardValidator::isValid("4539 1488 0343 6468")); // Invalid Visa
  EXPECT_FALSE(CreditCardValidator::isValid("6011-1111-1111-1118")); // Invalid Discover
  EXPECT_FALSE(CreditCardValidator::isValid("3714 4963 5398 432")); // Invalid American Express
}

/// Edge cases
TEST(CreditCardValidatorTest, NonNumericInput) {
  EXPECT_FALSE(CreditCardValidator::isValid("1234")); // Too short
  EXPECT_FALSE(CreditCardValidator::isValid("12345678901234567890")); // Too long
  EXPECT_FALSE(CreditCardValidator::isValid("")); // Empty input
}
