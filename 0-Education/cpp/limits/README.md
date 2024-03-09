# Integer Types

> short, int, long, long long의 limits를 도출하는 코드

## Output
### Window, 64-bit MSVC
```bash
int is 4 bytes.
short is 2 bytes.
long is 4 bytes.
long long is 8 bytes.

Maximun values:
int: 2147483647
short: 32767
long: 2147483647
long long: 9223372036854775807

Minimun int values = -2147483648
Minimun short values = -32768
Minimun long values = -2147483648
Minimun long long values = -9223372036854775808
Bits per byte = 8
```

### Linux, 64-bit gcc

## New Things
### long type depends on the system

### sizeof Operator

```c++
int a = 10;
sizeof a;       // valid
sizeof(a);      // valid
sizeof(int);    // valid
sizeof int;     // invlaid  
```

### Under/Overflow



### 