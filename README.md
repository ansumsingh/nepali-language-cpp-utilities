[![Linux build](https://github.com/ansumsingh/nepali-language-cpp-utilities/workflows/linux-build/badge.svg)](https://github.com/ansumsingh/nepali-language-cpp-utilities/actions)

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

**Requirements of the library**
- SRS-1 Convert romanized english characters to Nepali unicode ✔️
- SRS-2 Shall produce numbers into Nepali number text ✔️
- SRS-3 Shall stringify numbers ✔️
- SRS-4 Shall convert Date into Nepali date

### How to build locally?
Currently, this library has been setup to build for the linux only. Support for other platforms will be supported in the future. It uses conan for package managements.

#### Requirement for building locally
- Docker

#### Steps
1. Run `build_image_and_run.sh build_lib.sh` this will build a docker image and the library.

**TODO**
- Packaging 
- Add fuzz testting
- Make repository public and versioning
