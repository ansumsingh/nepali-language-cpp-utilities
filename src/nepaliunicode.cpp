#include "nepaliunicode.h"
#include <unordered_map>
#include <algorithm>

namespace 
{
const auto keyToNepali = std::unordered_map<char, wchar_t>{
  {'a', 0x093E}, // ा
  {'b', 0x092C}, // ब
  {'c', 0x091B}, // छ
  {'d', 0x0926}, // द 
  {'e', 0x0947}, // े 
  {'f', 0x0909}, // उ 
  {'g', 0x0917}, // ग 
  {'h', 0x0939}, // ह 
  {'i', 0x093F}, // ि 
  {'j', 0x091C}, // ज
  {'k', 0x0915}, // क
  {'l', 0x0932}, // ल
  {'m', 0x092E}, // म
  {'n', 0x0928}, // न
  {'o', 0x094B}, // ो
  {'p', 0x092A}, // प
  {'q', 0x091F}, // ट
  {'r', 0x0930}, // र
  {'s', 0x0938}, // स
  {'t', 0x0924}, // त
  {'u', 0x0941}, // ु
  {'v', 0x0935}, // व
  {'w', 0x094C}, // ौ
  {'x', 0x0921}, // ड
  {'y', 0x092F}, // य
  {'z', 0x0937}, // ष
  {'A', 0x0906}, // आ
  {'B', 0x092D}, // भ
  {'C', 0x091A}, // च
  {'D', 0x0927}, // ध
  {'E', 0x0948}, // ै
  {'F', 0x090A}, // ऊ
  {'G', 0x0918}, // घ
  {'H', 0x0905}, // अ
  {'I', 0x0940}, // ी
  {'J', 0x091D}, // झ
  {'K', 0x0916}, // ख
  {'L', 0x0933}, // ळ
  {'M', 0x0902}, // ं
  {'N', 0x0923}, // ण
  {'O', 0x0913}, // ओ
  {'P', 0x092B}, // फ
  {'Q', 0x0920}, // ठ
  {'R', 0x0943}, // ृ
  {'S', 0x0936}, // श
  {'T', 0x0925}, // थ
  {'U', 0x0942}, // ू
  {'V', 0x0901}, // ँ
  {'W', 0x0914}, // औ
  {'X', 0x0922}, // ढ
  {'Y', 0x091E}, // ञ
  {'Z', 0x090B}, // ऋ
  {'0', 0x0966}, // ०
  {'1', 0x0967}, // १
  {'2', 0x0968}, // २
  {'3', 0x0969}, // ३
  {'4', 0x096A}, // ४
  {'5', 0x096B}, // ५
  {'6', 0x096C}, // ६
  {'7', 0x096D}, // ७
  {'8', 0x096E}, // ८
  {'9', 0x096F}, // ९
  {'^', 0x005E}, // ^
  {'`', 0x093D}, // ऽ
  {'~', 0x093C}, // ़
  {'_', 0x0952}, // ॒
  {'+', 0x200C}, // ZWNJ
  {'=', 0x200D}, // ZWJ
  {'[', 0x0907}, // इ
  {'{', 0x0908}, // ई
  {']', 0x090F}, // ए
  {'}', 0x0910}, // ऐ
  {'\\', 0x0950}, // ॐ
  {'|', 0x0903},  // ः
  {'<', 0x0919}, // ङ
  {'.', 0x0964}, // ।
  {'>', 0x0965}, // ॥
  {'/', 0x094D}, // ्
  {'?', 0x003F}, // ?
};
}


std::wstring
nepaliunicode::convertToNepali(const std::string &romanized_nepali) {
  auto result = std::wstring{};
  std::transform(romanized_nepali.cbegin(), romanized_nepali.cend(),
                 std::back_inserter(result), [&](const char input_char) {
                   const auto found = keyToNepali.find(input_char);
                   if (found != keyToNepali.end()) {
                     return found->second;
                   }
                   return static_cast<wchar_t>(input_char);
                 });
   return result;
}
