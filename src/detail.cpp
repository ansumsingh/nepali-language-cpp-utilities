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

  const auto map_to_nepali_letter = std::unordered_map<wchar_t, wchar_t>{
    {'a', 0x093E},  // ा
    {'b', 0x092C},  // ब
    {'c', 0x091B},  // छ
    {'d', 0x0926},  // द
    {'e', 0x0947},  // े
    {'f', 0x0909},  // उ
    {'g', 0x0917},  // ग
    {'h', 0x0939},  // ह
    {'i', 0x093F},  // ि
    {'j', 0x091C},  // ज
    {'k', 0x0915},  // क
    {'l', 0x0932},  // ल
    {'m', 0x092E},  // म
    {'n', 0x0928},  // न
    {'o', 0x094B},  // ो
    {'p', 0x092A},  // प
    {'q', 0x091F},  // ट
    {'r', 0x0930},  // र
    {'s', 0x0938},  // स
    {'t', 0x0924},  // त
    {'u', 0x0941},  // ु
    {'v', 0x0935},  // व
    {'w', 0x094C},  // ौ
    {'x', 0x0921},  // ड
    {'y', 0x092F},  // य
    {'z', 0x0937},  // ष
    {'A', 0x0906},  // आ
    {'B', 0x092D},  // भ
    {'C', 0x091A},  // च
    {'D', 0x0927},  // ध
    {'E', 0x0948},  // ै
    {'F', 0x090A},  // ऊ
    {'G', 0x0918},  // घ
    {'H', 0x0905},  // अ
    {'I', 0x0940},  // ी
    {'J', 0x091D},  // झ
    {'K', 0x0916},  // ख
    {'L', 0x0933},  // ळ
    {'M', 0x0902},  // ं
    {'N', 0x0923},  // ण
    {'O', 0x0913},  // ओ
    {'P', 0x092B},  // फ
    {'Q', 0x0920},  // ठ
    {'R', 0x0943},  // ृ
    {'S', 0x0936},  // श
    {'T', 0x0925},  // थ
    {'U', 0x0942},  // ू
    {'V', 0x0901},  // ँ
    {'W', 0x0914},  // औ
    {'X', 0x0922},  // ढ
    {'Y', 0x091E},  // ञ
    {'Z', 0x090B},  // ऋ
    {'0', 0x0966},  // ०
    {'1', 0x0967},  // १
    {'2', 0x0968},  // २
    {'3', 0x0969},  // ३
    {'4', 0x096A},  // ४
    {'5', 0x096B},  // ५
    {'6', 0x096C},  // ६
    {'7', 0x096D},  // ७
    {'8', 0x096E},  // ८
    {'9', 0x096F},  // ९
    {'^', 0x005E},  // ^
    {'`', 0x093D},  // ऽ
    {'~', 0x093C},  // ़
    {'_', 0x0952},  // ॒
    {'+', 0x200C},  // ZWNJ
    {'=', 0x200D},  // ZWJ
    {'[', 0x0907},  // इ
    {'{', 0x0908},  // ई
    {']', 0x090F},  // ए
    {'}', 0x0910},  // ऐ
    {'\\', 0x0950}, // ॐ
    {'|', 0x0903},  // ः
    {'<', 0x0919},  // ङ
    {'.', 0x0964},  // ।
    {'>', 0x0965},  // ॥
    {'/', 0x094D},  // ्
    {'?', 0x003F},  // ?
};
}

std::optional<wchar_t>
nepali::detail::romanized_to_nepali_unicode(wchar_t romanized_char) {
  const auto found = map_to_nepali_letter.find(romanized_char);
  if (found != map_to_nepali_letter.end()) {
    return found->second;
  }
  return std::nullopt;
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