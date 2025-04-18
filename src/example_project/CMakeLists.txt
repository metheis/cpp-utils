# CMakeLists.txt for core_util

# Add source files in this directory
set(SOURCES
    credit_card_validator.cc
)

# Create a library target for the source files
add_library(credit_card_validator ${SOURCES})

# Add unit test binary
add_executable(
  credit_card_validator_test
  credit_card_validator_test.cc
)

# Link dependencies
target_link_libraries(credit_card_validator PUBLIC core_util)
target_link_libraries(credit_card_validator_test credit_card_validator)
target_link_libraries(credit_card_validator_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(credit_card_validator_test)
