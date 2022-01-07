#include "common.h"
#include "nepaliunicode.h"
#include <algorithm>
#include <catch2/catch.hpp>

namespace {
template<typename T>
void compare_vector(const std::vector<T>& expected, const std::vector<T>& result)
{
  REQUIRE(result.size() == expected.size());
  for (int i = 0; i < result.size(); i++) {
      INFO("Index not equal: " << i);
      REQUIRE(expected[i] == result[i]);
    }
}
} //namespace

namespace nepaliunicode {
namespace test {
TEST_CASE("to_nepali") {
  // Test the mapping
  SECTION("Test mapping") {
    auto results = std::vector<std::wstring>{};

    std::transform(romanized_chars.cbegin(), romanized_chars.cend(),
                   std::back_inserter(results), [](const auto &val) {
                     return nepaliunicode::to_nepali(val);
                   });

    compare_vector(expected_nepali_chars, results);
  }

  SECTION("Can convert romanized text to nepali") {
    const auto input_texts = std::vector<std::string>{
        "Aram", "tn/na", "ZRN", "ram/ro", "S/rIKN/x", "S/rIman/+ko", "mr/=yo",
    };
    
    const auto expected_texts = std::vector<std::wstring>{
        L"आराम",
        L"तन्ना",
        L"ऋृण",
        L"राम्रो",
        L"श्रीखण्ड",
        L"श्रीमान्‌को",
        L"मर्‍यो",
    };

    auto results = std::vector<std::wstring>{};
    std::transform(input_texts.cbegin(), input_texts.cend(),
                   std::back_inserter(results), [](const auto& input_text) {
                     return nepaliunicode::to_nepali(input_text);
                   });

    compare_vector(expected_texts, results);
  }

  SECTION("mixed input produce mixed result") {
    const auto input_texts = std::vector<std::string>{
        "<&", "k/ra#n/tI", "ks/)"
    };
    
    const auto expected_texts = std::vector<std::wstring>{
        L"ङ&", L"क्रा#न्ती", L"कस्)"
    };

    auto results = std::vector<std::wstring>{};
    std::transform(input_texts.cbegin(), input_texts.cend(),
                   std::back_inserter(results), [](const auto& input_text) {
                     return nepaliunicode::to_nepali(input_text);
                   });

    compare_vector(expected_texts, results);
  }
}
} // namespace test
} // namespace nepaliunicode