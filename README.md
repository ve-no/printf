
# CUSTOM PRINTF FUNCTION

The printf function in C is used for formatted output. It’s part of the Standard Input/Output       Library (stdio.h) and is responsible for printing data to the standard output (typically the        console) in a specified format. It’s an essential tool for displaying information to users and      debugging programs.

----------------------------------------------------------------------------------------------
#### Authorized functions and Macros
* write(man 2 write)
* malloc(man 3 malloc)
* free(man 3 free)
* va_start(man 3 va_start)
* va_end(man 3 va_end)
* va_copy(man 3 copy)
* va_arg( man 3 va_arg)
        
 ------------------------------------
 ### Compilation
    $ gcc -Wall -Werror -pedantic -std=gnu98 *.c
 ---------- | ------------------------------------------------------
      Qn    | -Functions
 ---------- | ----------------------------------------------------------------------------------
  1         |  - custom variadic function that prints an output according to a format provided.
  2         |  - handling d & i conversion specifiers.
  3         |  - handling unsigned int to binary b
  4         |  - handling u, o, x, X conversion specifiers
  5         |  - Local buffer
  6         |  - Print String
  7         |  - Handling 'p' conversion specifier
  8         |  - Handling non-custom conversion specifiers '+', '&nbsp', '#'
  9         |  - Handling l and h non-custom specifiers.
  10        |  - Precision non-custom conversion specifiers
  11        |  - 0 flag character
  12        |  - - Flag character
  13        |  - Print Reverse String
  14        |  - rot13'ed String
  15        |  :thumbs_up:


### 0-Print Anything
Prototype: int_printf(const char *format, ...);
Returns the number of characters printed(excluding the null character used to end the               output

### 1-Integers Conversion Specifiers
Handles 'd' and 'i' conversion specifiers without handling flag characters

### 13. Print a String in Reverse
     
    Retrieve a string argument from the variable argument list 
    If the string is NULL, assign a default value
    Calculate the length of the string
    Print the characters in reverse order
    For i from (j - 1) down to 0:
    Call _putchar(s[i])  // Print the character
    Return the length of the string
    
### Handle Custom Conversion Specifier 
    Identify the "R" specifier in the format string.
    Extract the corresponding argument (string) from the argument list.
    Apply the ROT13 transformation to the string.
    Print the ROT13-encoded string.
