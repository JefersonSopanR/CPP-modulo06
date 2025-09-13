# CPP Module 06

This project is part of the 42 School C++ curriculum, focusing on advanced concepts such as type conversion, serialization, and polymorphism. It consists of three exercises, each in its own directory.

## Table of Contents
- [ex00: Scalar Converter](#ex00-scalar-converter)
- [ex01: Serializer](#ex01-serializer)
- [ex02: Polymorphic Base](#ex02-polymorphic-base)
- [How to Build](#how-to-build)
- [Usage](#usage)
- [Author](#author)

---

## ex00: Scalar Converter
Implements a class `ScalarConverter` that converts a string literal to its corresponding scalar type (`char`, `int`, `float`, `double`).

- **Files:**
  - `main.cpp`
  - `ScalarConverter.cpp`
  - `ScalarConverter.hpp`
  - `Makefile`

### Features
- Detects and converts input to the correct scalar type.
- Handles special cases (pseudo-literals, overflow, etc).

---

## ex01: Serializer
Implements a class `Serializer` to serialize and deserialize pointers to a struct.

- **Files:**
  - `main.cpp`
  - `Serializer.cpp`
  - `Serializer.hpp`
  - `Makefile`

### Features
- Converts pointers to integer types and back.
- Demonstrates pointer manipulation and type safety.

---

## ex02: Polymorphic Base
Implements a polymorphic base class and derived classes, demonstrating dynamic casting and RTTI.

- **Files:**
  - `main.cpp`
  - `Base.cpp`
  - `Base.hpp`
  - `Makefile`

### Features
- Randomly generates instances of derived classes.
- Identifies the actual type of an object at runtime.

---

## How to Build
Each exercise contains its own `Makefile`. To build an exercise, navigate to its directory and run:

```bash
make
```

## Usage
After building, run the executable generated in each exercise directory:

```bash
./<executable_name>
```

Refer to each exercise's `main.cpp` for usage examples.

---

## Author
- Jeferson Sopan R

---

## License
This project is for educational purposes at 42 School.
