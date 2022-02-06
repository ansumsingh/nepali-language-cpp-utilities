#pragma once
#include "detail.h"
#include <algorithm>
#include <string>

namespace nepali {

template <class T,
          typename = std::enable_if_t<std::is_same<typename T::traits_type, std::char_traits<char>>::value ||
                                      std::is_same<typename T::traits_type, std::char_traits<wchar_t>>::value ||
                                      std::is_same<typename T::traits_type, std::char_traits<char16_t>>::value ||
                                      std::is_same<typename T::traits_type, std::char_traits<char32_t>>::value>>
std::wstring to_nepali(const T &romanized_nepali) {
  auto result = std::wstring{};
  std::transform(romanized_nepali.cbegin(), romanized_nepali.cend(),
                 std::back_inserter(result), [](const auto input_char) {
                   const auto found = detail::romanized_to_nepali_unicode(static_cast<wchar_t>(input_char));
                   if (found) {
                     return found.value();
                   }
                   return static_cast<wchar_t>(input_char);
                 });
  return result;
}

template <class T, typename = std::enable_if_t<std::is_unsigned<T>::value>>
std::wstring number_to_nepali_words(T input) {
  
  return detail::number_to_nepali_words(static_cast<uint64_t>(input));

}

} // namespace nepali
