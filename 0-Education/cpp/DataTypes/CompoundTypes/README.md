# Compound Types
> Array, String, Pointer, Structure, etc.

## array.cpp
### Output
```bash
Total yams = 21
The package with 8 yams costs 30 cents per yam.
The total yam expense is 410 cents.

Size of yams array = 12 bytes.
Size of one element = 4 bytes.

Hotel Tips: 5, 2.5, 0, 0, 0
Zeros: 0, 0
One: 1, 0, 0
Size of things: 4
```
### New Things to Know


## cinstr.cpp
## string.cpp
## str_arith.cpp


## structure.cpp
### Output
```bash
Expand your guest list with Glorious Gloria and Audacious Arthur!
You can have both for $62.98!
choice: Audacious Arthur for $32.99
The guests Glorious Gloria and Audacious Arthur
have a combined volume of 5 cubic feet.
The guests name's first characters are G, A, A, B, G.
```
### New Things to Know


## enum.cpp
### Output
```bash
blue assigned 4 constant
color assigned 3 constant
big step has 0, 100, 101
smallnums has 0, 0, 1, 1
```
### New Things to Know
Enumerate에는 정수형 상수가 0에서부터 순서대로 할당된다.
이때, 명시적으로 어떤 값을 할당할지 표현할 수 있으며, 이 경우 다음 enum 값은 할당된 값에 1을 더한 값부터 할당된다.

## address.cpp
### Output
```bash
donuts value = 6 and donuts address = 0000005DADAFF4B4
cups value = 4.5 and cups address = 0000005DADAFF4D8

*ptr(100) == val(100)
*ptr(500) == val(500)

Values: updates = 6, *p_updates = 6
Addresses: &updates = 0000005DADAFF534, p_updates = 0000005DADAFF534
Now updates = 7 and &updates = 0000005DADAFF534
Now *p_updates = 7 and p_updates = 0000005DADAFF534
Now updates = 7 and &updates = 0000005DADAFF534
Now *p_updates = -858993460 and p_updates = 0000005DADAFF538

1, 8
4, 8
8, 8
```
### New Things to Know

## ptr_arith.cpp
### Output
```bash
000000000000008C
0000000000000078
00000000000000B4
000000000000008C

pw = 00000098102FFA18, *pw = 10000
add 1 to the pw pointer:
pw = 00000098102FFA20, *pw = 20000

ps = 00000098102FFA44, *ps = 3
add 1 to the ps pointer:
ps = 00000098102FFA46, *ps = 2

access two elements with array notation
stacks[0] = 3, stacks[1] = 2
access two elements with pointer notation
*stacks = 3, *(stacks + 1) =  2
24 = size of wages array
8 = size of pw pointer

7
```
### New Things to Know


## use_new.cpp
### Output
```bash
nights value = 1001: location 0000003D630FFB64
int value = 1001: location = 000001A5C9C56F50
double value = 1e+07: location = 000001A5C9C64360
location of pointer pd: 0000003D630FFBA8
size of pt = 8: size of *pt = 4
size of pd = 8: size of *pd = 8
```
### New Things to Know
*pd는 pd가 가리키는 메모리 위치에 저장된 값에 접근하고, pd는 해당 메모리의 주소를 나타내며, &pd는 pd 포인터 변수 자체의 주소를 나타낸다.


## array_new.cpp
### Output
```bash
p3[0] is 0.2 and p3[1] is 0.5 and p3[2] is 0.8 and p3[3] is 1.50201e-307.
Now p3[0] is 0.5 and p3[1] is 0.8 and p3[2] is 1.50201e-307.
```
### New Things to Know
new로 선언한 array는 out of index가 warning으로 들어와도 실행이 된다.

## ptr_string.cpp
### Output
```bash
bear
b
bear

Using assignment operator(=):
bear at 0000002DB4AFF5A4
bear at 0000002DB4AFF5A4
Using strcpy() function:
bear at 0000002DB4AFF5A4
bear at 000001D09D2C4050
```
### New Things to Know
* 일반적으로 cout에 pointer type을 주면 저장된 address를 반환한다. 그러나 만약 pointer type이 (char *)일 경우, cout은 pointed-to string을 반환한다. 따라서 string의 주소를 출력하고 싶다면 (int *)와 같이 다른 pointer type으로 cast해야 한다.

* The prototpyes of standard library functions:
    - std::size_t strlen(const char* str);
    - char *strcpy(char *dest, const char* src); <br>
왜 (const char*)가 붙을까? 이 함수들이 수행되는 동안 들어온 string이 변하는 것을 방지하고자 함이다.

* 


## ptr_structure.cpp
### Output
```bash
Enter name of inflatable item: Fabulous Frodo
Enter volume in cubic feet: 1.4
Enter price: $27.99
Name: Fabulous Frodo
Volume: 1.4 cubic feet
Price: $27.99
```
### New Things to Know