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

constexpr uint64_t MAX_SUPPORTED_NUMBER = 99'99'99'99'99'99'99'99'999llu;
} //namespace

using namespace std::literals;

namespace nepali {
namespace test {
TEST_CASE("to_nepali") {
  SECTION("Test mapping") {
    auto results = std::vector<std::wstring>{};

    std::transform(romanized_chars.cbegin(), romanized_chars.cend(),
                   std::back_inserter(results), [](const auto &val) {
                     return nepali::to_nepali(val);
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
                     return nepali::to_nepali(input_text);
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
                     return nepali::to_nepali(input_text);
                   });

    compare_vector(expected_texts, results);
  }

  SECTION("Can pass std::string and std::string_view")
  {
    REQUIRE(nepali::to_nepali(std::string{"Aram"}) == L"आराम"s);
    REQUIRE(nepali::to_nepali("Aram"s) == L"आराम"s);
    REQUIRE(nepali::to_nepali(std::string_view{"Aram"}) == L"आराम"s);
    REQUIRE(nepali::to_nepali("Aram"sv) == L"आराम"s);
  }

  SECTION("Can pass std::wstring and std::wstring_view")
  {
    REQUIRE(nepali::to_nepali(std::wstring{L"Aram"}) == L"आराम"s);
    REQUIRE(nepali::to_nepali(L"Aram"s) == L"आराम"s);
    REQUIRE(nepali::to_nepali(std::wstring_view{L"Aram"}) == L"आराम"s);
    REQUIRE(nepali::to_nepali(L"Aram"sv) == L"आराम"s);
  }

  SECTION("Can pass std::u16string")
  {
    REQUIRE(nepali::to_nepali(std::u16string{u"Aram"}) == L"आराम"s);
    REQUIRE(nepali::to_nepali(u"Aram"s) == L"आराम"s);
    REQUIRE(nepali::to_nepali(std::u16string_view{u"Aram"}) == L"आराम"s);
    REQUIRE(nepali::to_nepali(u"Aram"sv) == L"आराम"s);
  }

  SECTION("Can pass std::u32string")
  {
    REQUIRE(nepali::to_nepali(std::u32string{U"Aram"}) == L"आराम"s);
    REQUIRE(nepali::to_nepali(U"Aram"s) == L"आराम"s);
    REQUIRE(nepali::to_nepali(std::u32string_view{U"Aram"}) == L"आराम"s);
    REQUIRE(nepali::to_nepali(U"Aram"sv) == L"आराम"s);
  }

  SECTION("Compilation fails if string is not provided")
  {
    //Uncomment the following to see that the compilation fails
    //nepali::to_nepali(std::vector<char>{});
  }
}

TEST_CASE("number_to_nepali_word")
{
  SECTION("Compilation fails if unsigned types not provided")
  {
    nepali::number_to_nepali_words(static_cast<uint>(1));
    nepali::number_to_nepali_words(static_cast<uint64_t>(1));
    nepali::number_to_nepali_words(static_cast<unsigned short>(1));
    nepali::number_to_nepali_words(static_cast<unsigned short int>(1));
    nepali::number_to_nepali_words(static_cast<unsigned long>(1));
    nepali::number_to_nepali_words(static_cast<unsigned long int>(1));
    nepali::number_to_nepali_words(static_cast<unsigned long long int>(1));
    nepali::number_to_nepali_words(static_cast<bool>(1));

    //Uncomment the following to see that the compilation fails
    // nepali::number_to_nepali_words(static_cast<char>(1));
    // nepali::number_to_nepali_words(static_cast<short>(1));
    // nepali::number_to_nepali_words(static_cast<short int>(1));
    // nepali::number_to_nepali_words(static_cast<long>(1));
    // nepali::number_to_nepali_words(static_cast<long int>(1));
    // nepali::number_to_nepali_words(static_cast<long long int>(1));
    // nepali::number_to_nepali_words(static_cast<int64_t>(1));
    // nepali::number_to_nepali_words(static_cast<int>(1));
    // nepali::number_to_nepali_words(static_cast<long>(1));
    // nepali::number_to_nepali_words(static_cast<float>(1));
    // nepali::number_to_nepali_words(static_cast<double>(1));
  }

  SECTION("returns empty if number > 99'99'99'99'99'99'99'99'999")
  {
    REQUIRE(nepali::number_to_nepali_words(MAX_SUPPORTED_NUMBER+1).empty());
  }

  SECTION("can convert from 0 to 99'99'99'99'99'99'99'99'999") {
    auto [input, expected] = GENERATE(
        std::make_pair(0llu, L"शुन्य"s), std::make_pair(1llu, L"एक"s),
        std::make_pair(11llu, L"एघार"s), std::make_pair(111llu, L"एक सय एघार"s),
        std::make_pair(1'111llu, L"एक हजार एक सय एघार"s),
        std::make_pair(1'11'111llu, L"एक लाख एघार हजार एक सय एघार"s),
        std::make_pair(1'11'11'111llu,
                       L"एक करोड एघार लाख एघार हजार एक सय एघार"s),
        std::make_pair(1'11'11'11'111llu,
                       L"एक अरव एघार करोड एघार लाख एघार हजार एक सय एघार"s),
        std::make_pair(
            1'11'11'11'11'111llu,
            L"एक खरव एघार अरव एघार करोड एघार लाख एघार हजार एक सय एघार"s),
        std::make_pair(
            1'11'11'11'11'11'111llu,
            L"एक नील एघार खरव एघार अरव एघार करोड एघार लाख एघार हजार एक सय एघार"s),
        std::make_pair(
            1'11'11'11'11'11'11'111llu,
            L"एक पदम एघार नील एघार खरव एघार अरव एघार करोड एघार लाख एघार हजार एक सय एघार"s),
        std::make_pair(
            1'11'11'11'11'11'11'11'111llu,
            L"एक शंख एघार पदम एघार नील एघार खरव एघार अरव एघार करोड एघार लाख एघार हजार एक सय एघार"s),
        std::make_pair(
            99'99'99'99'99'99'99'99'999llu,
            L"उनान्सय शंख उनान्सय पदम उनान्सय नील उनान्सय खरव उनान्सय अरव उनान्सय करोड उनान्सय लाख उनान्सय हजार नौ सय उनान्सय"s));

    REQUIRE(nepali::number_to_nepali_words(input) == expected);
  }
}
} // namespace test
} // namespace nepali