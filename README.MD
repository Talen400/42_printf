# ft_printf

A custom implementation of the C library function `printf` that handles various format specifiers and conversions.

## 📋 Description

The **ft_printf** project is about recoding the famous `printf` function from the C library. This project teaches about variadic functions, format specifiers, and string manipulation. It's a fundamental project from 42 São Paulo that helps understand how formatted output works under the hood.

## ✨ Features

### Supported Format Specifiers
- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer (base 10)
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal (lowercase)
- `%X` - Print a number in hexadecimal (uppercase)
- `%%` - Print a literal percent sign

## 🏗️ Project Structure

```
📁 ft_printf/
├── 📄 ft_printf.c          # Main printf implementation
├── 📄 ft_printf.h          # Header file
├── 📄 ...                  # Utility functions for conversions
├── 📄 Makefile            # Compilation rules
└── 📄 README.md           # This file
```

## 🔧 Implementation

### Function Prototype
```c
int ft_printf(const char *format, ...);
```

## 🚀 How to Use

### Compilation
```bash
make        # Compiles the library
make clean  # Removes object files
make fclean # Removes object files and library
make re     # Recompiles everything
```

### Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    char *str = "Hello";
    int num = 42;
    void *ptr = &num;
    
    ft_printf("String: %s\n", str);
    ft_printf("Number: %d\n", num);
    ft_printf("Hex: %x\n", num);
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Percent: %%\n");
    
    return (0);
}
```

### Compilation with Your Project
```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lftprintf
```

## ⚙️ Technical Details

### Return Value
Returns the number of characters printed (excluding the null terminator), just like the original `printf`.

### Error Handling
- Handles NULL string pointers
- Properly manages memory allocation
- Returns -1 on write errors

## 🧪 Test Cases

The function should handle:
- Empty strings
- NULL pointers
- Very large numbers
- Negative numbers
- Zero values
- Mixed format specifiers
- Edge cases for each conversion

### Example Test Cases
```c
ft_printf("Empty string: '%s'\n", "");
ft_printf("NULL string: '%s'\n", NULL);
ft_printf("Zero: %d\n", 0);
ft_printf("Negative: %d\n", -42);
ft_printf("Large number: %u\n", 4294967295U);
ft_printf("Hex lowercase: %x\n", 255);
ft_printf("Hex uppercase: %X\n", 255);
```

## 📊 Complexity

- **Time**: O(n) where n is the length of the output
- **Space**: O(1) for most conversions, O(log n) for number conversions

## 🔍 Implementation Details

### Variadic Arguments
Uses the `stdarg.h` library to handle variable number of arguments:
```c
va_list args;
va_start(args, format);
// Process arguments
va_end(args);
```

### Format String Parsing
Iterates through the format string character by character, identifying format specifiers and processing them accordingly.

### Number Base Conversions
- **Decimal**: Standard base-10 conversion
- **Hexadecimal**: Base-16 conversion with appropriate character mapping
- **Pointer**: Special handling for pointer addresses

## 🛠️ Makefile Targets

```makefile
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
```

## 🧩 Algorithm Overview

1. **Parse**: Iterate through format string
2. **Identify**: Detect format specifiers (%)
3. **Extract**: Get the next variadic argument
4. **Convert**: Convert argument to appropriate string format
5. **Output**: Write to standard output
6. **Count**: Track number of characters printed

## 🔧 Bonus Features (Not Implemented)
This implementation focuses on core functionality and does not include advanced features like field width, precision, or alignment flags.

## 👤 Author

**tlavared** - 42 São Paulo

---

*Made with ❤️ at 42 São Paulo*
