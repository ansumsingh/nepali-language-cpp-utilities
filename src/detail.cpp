#include "detail.h"

#include <vector>
#include <algorithm>

#include <cassert>

namespace {
  using namespace std::literals;
  constexpr uint64_t MAX_SUPPORTED_NUMBER = 99'99'99'99'99'99'99'99'999llu;

  const auto scale_names = std::vector<std::pair<uint64_t, std::wstring>>{
    {1'00'00'00'00'00'00'00'000llu, L"शंख"s},
    {1'00'00'00'00'00'00'000llu, L"पदम"s},
    {1'00'00'00'00'00'000llu, L"नील"s},
    {1'00'00'00'00'000llu, L"खरव"s},
    {1'00'00'00'000llu, L"अरव"s},
    {1'00'00'000llu, L"करोड"s},
    {1'00'000llu, L"लाख"s},
    {1'000llu, L"हजार"s},
    {100llu, L"सय"s},
    {1llu, L"None"s}
  };

  const auto count_upto_99 = std::vector<std::wstring>{
      L"शुन्य"s,     L"एक"s,      L"दुई"s,      L"तिन"s,      L"चार"s,
      L"पाँच"s,     L"छ"s,       L"सात"s,     L"आठ"s,       L"नौ"s,
      L"दस"s,      L"एघार"s,    L"बाह्र"s,    L"तेह्र"s,      L"चौध"s,
      L"पन्ध्र"s,    L"सोह्र"s,    L"सत्र"s,     L"अठार"s,     L"उन्नाइस"s,
      L"बिस"s,     L"एक्काइस"s,  L"बाइस"s,    L"तेइस"s,      L"चौबिस"s,
      L"पच्चिस"s,   L"छब्बिस"s,   L"सत्ताइस"s,  L"अट्ठाइस"s,   L"उनन्तिस"s,
      L"तिस"s,     L"एकतिस"s,   L"बत्तिस"s,   L"तेत्तिस"s,    L"चौँतिस"s,
      L"पैँतिस"s,    L"छत्तिस"s,   L"सैँतिस"s,    L"अठतिस"s,    L"उनन्चालिस"s,
      L"चालिस"s,   L"एकचालिस"s, L"बयालिस"s,  L"त्रिचालिस"s, L"चवालिस"s,
      L"पैँतालिस"s,  L"छयालिस"s,  L"सतचालिस"s, L"अठचालिस"s,  L"उनन्चास"s,
      L"पचास"s,    L"एकाउन्न"s,  L"बाउन्न"s,   L"त्रिपन्न"s,   L"चवन्न"s,
      L"पचपन्न"s,   L"छपन्न"s,    L"सन्ताउन्न"s, L"अन्ठाउन्न"s,  L"उनन्साठी"s,
      L"साठी"s,    L"एकसट्ठी"s,  L"बयसट्ठी"s,  L"त्रिसट्ठी"s,  L"चौसट्ठी"s,
      L"पैँसट्ठी"s,   L"छयसट्ठी"s,  L"सतसट्ठी"s,  L"अठसट्ठी"s,   L"उनन्सत्तरी"s,
      L"सत्तरी"s,   L"एकहत्तर"s,  L"बहत्तर"s,   L"त्रिहत्तर"s,  L"चौहत्तर"s,
      L"पचहत्तर"s,  L"छयहत्तर"s,  L"सतहत्तर"s,  L"अठहत्तर"s,   L"उनासी"s,
      L"असी"s,     L"एकासी"s,   L"बयासी"s,   L"त्रियासी"s,  L"चौरासी"s,
      L"पचासी"s,   L"छयासी"s,   L"सतासी"s,   L"अठासी"s,    L"उनान्नब्बे"s,
      L"नब्बे"s,     L"एकानब्बे"s,  L"बयानब्बे"s,  L"त्रियानब्बे"s, L"चौरानब्बे"s,
      L"पन्चानब्बे"s, L"छयानब्बे"s,  L"सन्तानब्बे"s, L"अन्ठानब्बे"s,  L"उनान्सय"s,
  };
}

std::wstring nepali::detail::number_to_nepali_words(uint64_t input) {
  if (input > MAX_SUPPORTED_NUMBER) {
    return std::wstring{};
  }

  auto scale_values = std::vector<std::pair<std::wstring, uint64_t>>{};

  std::transform(scale_names.cbegin(), scale_names.cend(),
                 std::back_inserter(scale_values), [&](const auto &scale_name) {
                   const auto quotient = input / scale_name.first;
                   const auto remainder = input % scale_name.first;
                   input = remainder;
                   return std::make_pair(scale_name.second, quotient);
                 });

  auto result = std::wstring{};
  for (const auto &[scale, value] : scale_values) {
    // Debug assert to check if the requirement is not met.
    assert(value < 100);
    if (value > 0 && scale != L"None"s) {
      result += count_upto_99[value] + L" "s + scale + L" "s;
    }
    if (scale == L"None"s)
      result += count_upto_99[value];
  }
  return result;
}