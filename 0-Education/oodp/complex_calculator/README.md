# Complex Calculator
복소수 사칙연산을 지원하는 계산기를 c++로 간단하게 작성하였다.

## C++의 세가지 패러다임을 표현하려는 목적에서 작성되었다.
1. Structured Programming
순차적으로만 작동하는 코드가 아닌, 함수를 main 밖에서 구현해 호출한다.
   
3. Object-Oriented Programming
class를 구현하여, 멤버 변수와 멤버 함수를 작성하고 이를 main에서 호출해온다. [[github]](https://github.com/baejaeho18/code/blob/8b30340d71af0609e32312eed8ef36909fd7dd89/0-Education/oodp/complex_calculator/complex_calculator.cpp) <br>
[header 파일](https://github.com/baejaeho18/code/blob/a61bca4b70337f9f2b90e047ef2b1248920b4e53/0-Education/oodp/complex_calculator/complex_number_oop.h)에는 class 선언만,
정의는 [별도의 source 파일](https://github.com/baejaeho18/code/blob/a61bca4b70337f9f2b90e047ef2b1248920b4e53/0-Education/oodp/complex_calculator/complex_number_oop.cpp)에서 구현하여 불러올 수도 있다.

5. Generic Programming
Template을 사용하여 class를 구현한다. OOP에서는 class 내부 변수가 고정되어 있었지만, float/double 등 원하는 타입의 변수를 담을 수 있다. <br>
Template을 헤더파일에 정의할 때는, 선언부만 봐서는 compile time에서는 사용된 변수가 무엇인지 알 수가 없다. [[blog]](https://hwan-shell.tistory.com/253)
따라서 선언부와 구현부를 모두 [header file](https://github.com/baejaeho18/code/blob/fdfdc4a0877b19077fe5ca0a8bfe9d52ec4f1f25/0-Education/oodp/complex_calculator/complex_number_generic.h)에 넣어줘야 한다. 

## Output
```bash
Complex number calculator
What operation do you want to compute?(EXIT) +
Input the first number (real, imaginary): 2 4
Input the second number (Real, imaginzry): 1 -6
2+4i + 1-6i = 3-2i
What operation do you want to compute?(EXIT) -
Input the first number (real, imaginary): 2 0
Input the second number (Real, imaginzry): 1 1
2+0i - 1+1i = 1-1i
What operation do you want to compute?(EXIT) EXIT
```
