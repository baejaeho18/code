## 프로그램 개요
순서가 있는 LinkedList와 저장된 개수를 원소로 하는 struct OrderedList를 구현하고 테스트하는 프로그램이다. LinkedList에 저장되는 데이터는 항상 integer type이라고 가정한다.
LinkedList에 저장하는 값은 integer value 하나일 수도 있고, integer array일 수도 있다. 둘 모두 overloading된 add() 함수로 저장된다. 저장된 값은 remove() 함수에서 index로 접근해 삭제할 수 있다. size() 함수는 저장된 데이터의 개수를 출력한다. 특정 값이 존재하는지 확인하려면 contains() 함수를 호출하여 bool type을 반환 받는다. 특정 index에 어떤 값이 존재하는지 확인하려면 getValue() 함수를 호출하여 반환 받는다.
Test 실행 결과는 다음과 같다.
```bash
<<Simple Test 1>>
3, 4, 5, 50, 80,
<<Simple Test 2>>
3, 4, 5, 10, 10, 20, 35, 35, 50, 80,
<<Simple Test 3>>
3, 4, 5, 10, 20, 35, 35, 50, 80,
<<Simple Test 4>>
true
false
<<Simple Test 5>>
9
<<Simple Test 6>>
4, 5, 10, 20, 35, 35, 50, 80, -2147483648,
<<Simple Test 7>>
-2147483648, -1, 0, 2, 4, 5, 7, 10, 20, 35, 35, 50, 80, 90, -2147483648,
<<Simple Test 8>>
remove(): Out-of-index
remove(): Out-of-index
-1, 0, 2, 4, 5, 7, 10, 20, 35, 35, 50, 80,
```
 

## 프로그램의 구조 및 알고리즘
본 프로그램은 prob1.cpp, prob1.h, prob1_main.cpp의 세 파일로 구성되어 있다. prob1.h는 OrderedList와 LinkedList를 구현한 struct와, 이를 다루는 함수들을 선언한다. 본 프록램이 요구하는 LinkedList를 구현하기 위해서는 데이터를 저장하기 위한 변수와 다음 node를 가리키는 포인터 변수 하나가 필요하다. 다음과 같다.
```c++
struct Node {
	int element;
	Node* next;
};
```
위의 Node 구조체에서 값을 저장해나가면 OrderedList에서 필요한 것은 저장된 값의 개수와 LinkedList의 첫 node를 가리키는 포인터뿐이다. 다음과 같다.
```c++
struct OrderedList {
	int m_size;
	Node* head;
};
```
이어, 필요한 add(), remove(), size(), contains, getValue() 함수들의 prototype을 선언한다.
prob1.cpp는 prob1.h에서 선언된 함수들을 실제로 구현한다. 먼저 overloading된 두 add() 함수를 구현한다. 우선 integer value 하나를 저장하는 add(OrderedList* ordered, int v)를 구현하면, integer array를 저장하는 add() 함수는 배열의 각 원소마다 add(OrderedList* ordered, int v)를 호출하면 된다. add() 함수는 전달 받은 int v를 저장하는 Node 타입의 변수, node를 초기화한다. 그리고 orderedList가 가리키는 linkedList를 순회하며 v 보다 큰 값을 찾으면 해당 노드(crnt) 앞에 node를 삽입한다. 다음과 같이 구현된다.
```c++
node->next = crnt->next;
crnt->next = node;
ordered->m_size++;
```
remove() 함수는 입력 받은 index까지 linkedList를 순회하여 해당 노드를 기준으로 앞의 노드와 뒤의 노드를 곧바로 이어준다. 다음과 같이 구현된다.
```c++
prev->next = crnt->next;
```
한편, size() 함수는 OrderedList에 저장된 m_size를 반환한다. 이를 위해 remove()와 add() 함수들은 새로운 Node를 삽입하거나 삭제할 때, 반드시 m_size를 변경해주어야 한다. contains()와 getValue() 함수 모두 linkedList를 순회하며 특정 값을 찾는다. 다만 contains() 함수는 전달 받은 int v와 동일한 값을 찾고, getValue() 함수는 전달 받은 idx의 값을 반환한다. 만약 getValue() 함수가 전달 받은 idx가 linkedlist의 범위를 벗어난다면 minimum integer(-2147483648)을 출력한다. 다음과 같이 구현되었다.
``` c++
if (idx < 0 || ordered->m_size <= idx)
	return std::numeric_limits<int>::min();
```
마지막으로 prob1_main.cpp는 prob1에서 구현한 코드가 의도한대로 작동하는지 테스트한다. simpleTest1은 하나의 정수형 상수를 입력 받아 순서대로 저장하는지 확인한다. simpleTest2는 정수형 배열을 입력 받아 순서대로 저장하는지 확인한다. simpleTest3은 올바른 idx의 값이 삭제되는지 확인한다. simpleTest4는 contains() 함수가 정확하게 bool 결과를 반환하는지 확인한다. simpleTest5는 m_size가 적절히 반영되고 있는지 확인한다. simpleTest6과 7은 out-of-index 상황에서 getValue() 함수가 integer minimun을 출력하는지 확인한다. simpleTest8은 remove() 함수에도 out-of-index 예외처리를 한 결과를 확인한다.
 

## 토론 및 개선
remove() 함수에서 out-of-index 상황이 나오면 Segmentation Fault가 발생하며 프로그램이 강제 종료된다. 과제에서 제시되지는 않았지만 이러한 상황을 예외처리하여 에러메시지만 출력하고 다음 코드를 실행할 수 있도록 하였다. 구현은 다음과 같다.
```c++
if (index < 0 || ordered->m_size <= index) {
	std::cout << "remove(): Out-of-index" << std::endl;
	return;
}
```
본 프로그램의 가장 큰 문제는 add, remove, contains, getValue 모두 linkedList를 순회하도록 구현되어 있다는 것이다. 최악의 상황에서 모든 node를 참고해야한다. simpleTest처럼 작은 단위의 원소들을 저장할 때는 별 문제 없지만, 만약 만단위, 백만단위의 데이터를 저장해야할 때는 실행 속도가 극단적으로 떨어질 수 있다. 이러한 문제를 해결하기 위해, 임의의 간격의 노드의 데이터와 포인터를 저장하는 summary라는 linkedList를 별도로 선언할 수 있다. 임의의 간격은 저장된 번째수(index)일 수도 있고, 저장된 값(element)일 수도 있다. 예를 들어, 1만 단위의 OrderedList가 있을 때, 0번째, 100번째, 200번째, …, 1만 번째 node로 구성된 100개 노드를 가진 summary가 생성되는 방식이다. 이 경우, 위의 함수들은 summary를 먼저 순회한 후, summary의 두 노드 사이 즉, 100개 노드만 더 순회하면 삽입/삭제/검색하는 노드의 위치를 찾을 수 있다. 최악의 경우 1만번의 순회에서 200번의 순회로 감소하는 것이다. 다음과 같이 구현할 수 있을 것이다.
```c++
struct summary_node {
	int element;
	Node* origin_node;
	Node* next_summary_node;
}
```
