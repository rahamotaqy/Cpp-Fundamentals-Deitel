# Cpp-Fundamentals-Deitel

A clean, buildable collection of exercises and examples from *C++ How to Program* by Deitel & Deitel. Each chapter has its own directory with a short README and every exercise is a standalone CMake target.

> **Note from the author:** I originally wrote these exercises more than 12 years ago, as my first step into software engineering. The code reflects my learning path at that time, including the original Visual Studio style, comments, and some bugs I left untouched to preserve the authentic learning record. The modern comments explaining the correct portable form and the reasons behind the issues were added by an AI assistant during a recent cleanup.

## Project Structure

```
.
├── Chapter_07/   Arrays and vectors in classes / file processing
├── Chapter_09/   Classes: a deeper look (constructors, destructors, friends)
├── Chapter_10/   Classes: a deeper look, part 2 (static, const, composition)
├── Chapter_11/   Operator overloading (arrays, dates, strings)
├── Chapter_13/   Polymorphism and virtual functions
├── Chapter_14/   Class templates
├── Chapter_15/   Stream input/output
├── Chapter_16/   Exception handling and smart pointers
├── Chapter_17/   File processing and random-access files
├── Chapter_20/   Sorting algorithms (merge sort)
├── Chapter_21/   Linked-list data structure
├── CMakeLists.txt
└── .gitignore
```

## Build Instructions

You need CMake 3.10+ and a C++11 compiler.

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
```

To build a single exercise:

```bash
cmake --build build --target exercise_11.array_class
```

All build artifacts go into `build/` and are ignored by Git.

## Notes

- The original Visual Studio solution files, `Debug/` folders, `.sdf`/`.suo` files and other IDE artifacts were removed.
- Windows-specific precompiled-header boilerplate (`stdafx.h`, `targetver.h`, `_tmain`) was stripped so the code compiles with any standard C++ compiler.
- Chapter 17's random-access file exercises share a single portable `client_data.hpp`.
- Chapter 16's `auto_ptr` example was modernized to `std::unique_ptr` because `auto_ptr` was removed in C++17.

## License

The code is derived from Deitel & Deitel exercise prompts and adapted for personal learning.
