# नेपालीunicodeC++
A simple and easy-to-use C++ library that provides utilities for nepali language. 

## Key Features
- Provides a conversion API that takes text (romanized keyboard text) and convert to unicode.
- Simple APIs

## Usage 
### Convert to nepali unicode
```
  auto nepali_text = nepaliunicode::to_nepali(romanized_text);
```

**Requirements**
- SRS-1 Convert romanized english characters to Nepali unicode
- SRS-2 Shall produce numbers into Nepali number text
- SRS-3 Shall stringify numbers
- SRS-4 Shall convert Date into Nepali date

**TODO**
- Packaging 
- Add a function for SRS-2 and SRS-3
