#pragma once
#include <unordered_map>
#include <optional>

namespace nepali::detail {

std::optional<wchar_t> romanized_to_nepali_unicode(wchar_t romanized_char);

std::wstring number_to_nepali_words(uint64_t input);
} // namespace nepali::detail