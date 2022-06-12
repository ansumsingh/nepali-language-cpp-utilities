![Linux build](https://github.com/ansumsingh/nepali-language-cpp-utilities/.github/workflows/cmake.yaml/badge.svg)

# नेपाली language C++ utilities
A simple and easy-to-use C++ library that provides utilities for nepali language. 

## Key Features
- Provides a conversion API that takes text (romanized keyboard text) and convert to unicode.
- Provides an API that converts unsigned number to nepali word, e.g. 1111 -> एक हजार एक सय एघार
- Simple APIs

## Usage 
### Convert to nepali unicode
```
  assert(nepali::to_nepali(L"Aram"s) == L"आराम"s);
```

### Convert number to word
```
  assert(nepali::number_to_nepali_word(1111) == L"एक हजार एक सय एघार"s);
```

**Requirements**
- SRS-1 Convert romanized english characters to Nepali unicode
- SRS-2 Shall produce numbers into Nepali number text
- SRS-3 Shall stringify numbers
- SRS-4 Shall convert Date into Nepali date

**TODO**
- Packaging 
- Build in Github CI.
- Add fuzz testting
- Make repository public and versioning
