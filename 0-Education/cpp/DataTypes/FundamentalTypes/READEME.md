# C/C++ Data Types

## Output
### hexoct.cpp
```bash
Integer Literals of 42:
decimal     = 42 (42 in decimal)
hexadecimal = 66 (0x42 in hex : 16*4+2)
octal       = 34 (042 in octal : 8*4+2)

decimal     = 42 (decimal for 42)
hexadecimal = 2a(hexadecimal for 42 : 16*2+10)
octal       = 52 (octal for 42 : 8*5+2)
```

### bondini.cpp
```bash
Operation "HyperHype" is now activated!
Enter your agent code:1234____
You entered 1234...
Code verified!
Proceed with Plan Z3!
```

### chartype.cpp
```bash
Enter a character:
M
Hola! Thank you for the M character.
The ASCII code for M is 77
Add one to the character code:
The ASCII code for N is 78
Displaying char ch using cout.put(ch): NNNN!
Done
```

### const.cpp
```bash
Area is 78.5

Number of wheels of car is 20.

Enter the number of wheels per bicycle: 3
Number of wheels of bicycle is 9.
```


### float_artih.cpp
```bash
tub = 3.333333, a million tubs = 3333333.250000,
and ten million tubs = 33333332.000000
mint = 3.333333 and a million mint = 3333333.333333
a = 23400001102275227418624.000000
b - a = 0.000000
Integer division: 9/5 = 1
Floating-point division: 9.0/5.0 = 1.800000
Mixed division: 9.0/5 = 1.800000
double Constants: 1e7/9.0 = 1111111.111111
float constatns: 1e7f/9.0f = 1111111.125000
```

### init_cast.cpp
```bash
tree = 31.000000
guess = 3
debt = 1634811904

auks = 31, bats = 30, coots = 30
The code for Z is 90
```

## New Things to Know
### hexoct.cpp

### bondini.cpp

### chartype.cpp


### const.cpp
> Compare with **#define** and **const**


### float_artih.cpp
Normally cout drops trailing zeros. For example, it would display 3333333.250000 as 3333333.25. The call to **cout.setf()** overrides that behaviour.
The reason why float tub and double mint display different value after multiplies million(1.0E+6) is float has 7 siginificant figures while double has 13 sigificant figures.
- E notation : 3.45E6 == 3.45 * 10^6
- By default, Floating-Point constant is **double**

### init_cast.cpp



## bitwise.cpp
### Output
```bash
a = 13  : 00001101 (1 bytes)
b = 22  : 00010110 (1 bytes)
sl_a = 104      : 01101000 (1 bytes)
sr_a = 1        : 00000001 (1 bytes)
neg_a = 242     : 11110010 (1 bytes)
a_and_b = 4     : 00000100 (1 bytes)
a_or_b = 31     : 00011111 (1 bytes)
a_xor_B = 27    : 00011011 (1 bytes)
```

## bit_displayer.h
### Test I/O
```bash

```
