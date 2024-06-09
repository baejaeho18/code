# 1.	프로그램 개요
C++ class를 이용해 다양한 객체들이 상호작용하며 동작하는 텍스트 기반의 RPG 게임이다. 8x8개의 Room으로 이루어진 Map 안에서 (w,a,s,d) 방향키를 이용해 Playable-Character가 이동한다. Room에는 Monster, Boss가 존재하며, 때로는 비어있거나 Shop이 있고, 임의의 이벤트가 발생할 수도 있다. Shop을 제외한 방문한 방은 비어진다. Character와 Monster가 조우하면 서로 한 턴씩 교환하며 공격하는데, 게이머는 어떤 공격을 할 것인지 결정할 수 있다. Monster를 무찔러 얻은 보상으로 Shop에서 필요한 버프를 구매하거나 레벨업할 수 있다. 만약 Monster에게 패배하면 게임이 종료된다. 마지막 Boss를 처치하면 게임이 클리어된다.
 
# 2.	프로그램의 구조 및 알고리즘
본 프로그램은 크게 셋으로 나뉜다. 게임의 시작과 진행을 맡는 main, 게임 진행의 세부 동작을 정의한 menu, 그리고 게임의 구성요소인 여러 class들이다.

## 2.1
main.cpp에서는 menu.h의 여러 함수들을 호출하여 게임을 시작하고 진행시킨다. 먼저 start_game()을 호출하여 게임을 시작 여부를 묻는다. 이후, map.show_map()을 호출하여 gamer의 현재 위치와 방문한 room을 알려주는 8x8 Map을 보여주고, 게이머에게 선택지를 고르는 과정을 게임의 종료조건(character 사망 혹은 boss 처치, exit 선택)을 만족할 때까지 반복한다. progress_game()으로 선택지를 고르도록 한다. 게이머가 이동을 골랐다면 move_character()를 호출하고, status 조회를 골랐다면 show_character_status()를 호출한다. 이동한 방의 종류에 따라 random_encounter() 혹은 fight(), shopping()을 호출한다. fight()를 호출하기 전, Room 종류가 Monster라면 시작 위치와 현재 위치의 맨하튼 거리인 difficulty에 따라 적의 스펙이 결정되고, Boss라면 고정된 스펙으로 적이 생성된다. 게이머가 게임 종료를 골랐다면 게임을 종료한다. 이때, 게임 상의 모든 메뉴 선택은 게이머의 응답이 가능한 선택지일 때까지 반복된다.
      
 
## 2.2
menu.cpp는 위의 main이 호출한 6개의 함수를 구현한다. 이를 위해 menu.h는 character.h, monster.h, shop.h, map.h를 import한다. 먼저, bool start_game()은 TextRPG 로고를 보여주면서 게임을 시작할 것인지 여부를 묻고, 허용된 게이머의 응답(1 or 2)만을 반환한다.
      
int progress_game()은 character가 움직일 것인지, character의 status를 확인할 것인지, 게임을 종료할 것인지 응답을 받아 반환한다. Room move_character(Map& map)는 이동할 방향(w,a,s,d)을 입력 받고, 움직을 수 있는 방향이라면 이동하여 현재 의치의 Room 종류을 반환한다. 이동할 수 없다면 다음과 같은 메시지를 출력한다.
    
void random_encounter(Character& gamer)는 이동한 Room이 RANDOM 일 때, main에서 호출된다. 현재 체력 비례 데미지를 입히는 percentage_damage(), 잃은 체력 비례 회복을 주는 percentage_restore(), 100골드를 지급하는 looting_gold()와 아무일도 일어나지 않는 총 4개의 이벤트 중 하나를 임의로 실행하였음을 안내한다. 
    
Result fight(Character& gamer, Monster& enemy)는 이동한 Room이 MONSTER 혹은 BOSS 일 때, main이 호출한다. 매 턴마다 Character와 Monster의 현재 스텟창을 보여주고, 번걸아가며 공격한다. 게이머는 어떤 공격을 할 것인지 결정할 수 있다. Character의 hp가 바닥나면 사망메시지와 함께 LOSE를 반환한다. 
     
Monster의 hp가 먼저 0이 되면 Boss일 경우 게임 클리어 메시지가 출력되고, 일반 Monster라면 승리 메시지와 스펙에 비럐하는 보상(gold, exp)를 획득했다는 메시지가 출력되며 WIN을 반환한다. LOSE와 WIN은 menu.h에서 enum Result { LOSE, WIN }; 으로 정의되어 있다. 마지막으로 void shopping(Shop& shop, Character& gamer)은 Item 목록을 출력한 후, 게이머에게 구매할 물품을 선택하도록 한다. 구매하지 않고도 Shop을 나갈 수 있다. 만약 선택한 물품의 재고가 없거나, Character의 예산(gold)가 부족할 경우, 구매할 수 없는 이유를 출력한다. 구매 가능여부는 shop.{item_name}_available()과 gamer.purchasable(cost)를 호출하여 확인한다.
   
purchase()를 호출하여 무언가를 구매했다면 변화한 Character의 status와 Item 목록을 출력한다.
    

## 2.3
다음은 menu에서 사용된 map, shop, character, monster라는 4개의 class에 대한 설명이다.

### 2.3.1 
먼저 map은 main에서 초기화되어, menu의 move_character()에서 사용된다. Map()은 초기화와 동시에 Character의 현재 위치를 가리키는 x, y 좌표를 0으로 초기화한다. 그러나 그보다 앞서 class는 8x8 Map의 각 Room을 정의하는 Room mapping[8][8]과 방문 여부를 확인하는 Visit visited[8][8]를 정의해둔다. 각각 enum Room { EMPTY = 1, RANDOM, MONSTER, SHOP, BOSS }; 와 enum Visit { MYST, VISIT }; 로 정의된 int형 상수로 이루어진 배열이다. main에서 호출하는 void show_map()은 Map의 멤버변수인 x와 y, visited를 활용해 8x8 Map 상에서의 현재 위치를 “You”로, 방문하지 않은 Room을 “?”로 출력해 알려준다. menu의 move_character()에서 호출하는 int movable(char direction)는 현재위치(x,y)에 의거하여 입력 받은 이동방향이 불가능하다면 0(false), 가능하다면 이동한 위치의 Room 타입을 반환한다. Room 상수들은 1~5로 정의되어 있기 때문에 int형으로 함수가 선언되었다. int distance()는 현재 위치(x, y)와 시작 위치(0, 0) 간의 맨허튼 거리를 계산하여 반환한다. 이는 main에서 Monster의 난이도를 책정하는데 사용된다.
### 2.3.2
두번째로, shop class는 역시 map class처럼 게임 전체에서 일관되게 정보를 담아야하기에 main에서 선언되어, menu의 shopping()에서 사용된다. 선언과 동시에 판매 물품들의 정보를 담은 Item items[6]가 정의된다. Item은 물품 이름(name)과 상승수치(buf), 가격(cost), 재고(inventory) 정보를 담은 구조체이다. 판매 물픔이 5개인데 items가 6개 원소로 구성되어 있는 것은 Items 상수와 menu에서 게이머가 고르는 선택지를 일치시키기 위함이다.
 
### 2.3.3 
세번째 class는 character이다. character 클래스는 현재 status 정보와, 레벨업 등의 이번트로 변화하기 전의 status 정보를 member data로 갖는다. Character()는 이러한 member data들을 시작 시점(level 1)의 스펙으로 초기화한다. ~Map()과 ~Shop()의 사례와 같이 destructor는 동적할당을 하지 않아 필요하지 않기에 별도로 구현하지 않았다. member data들 중 getter 혹은 setter가 필요한 것은 int gold 하나 뿐이다. Menu의 shopping()에서 현재 예산으로 구매 여부를 확인하기 때문에 getter가 필요하다. getGold() 외에 필요한 member method는 다음과 같다.
```c++
// level up
void level_up_if_possible();			// by fight
void level_up_if_possible(int prev_curr_exp_);	// by shopping
// fight
void attack_basic(Monster& enemy);
void attack_skill(Monster& enemy);
void attack_fire(Monster& enemy);
void attack_grass(Monster& enemy);
void attack_water(Monster& enemy);
int injured(int damage);
bool is_alive();	
// show status
void show_character_status();
void show_character_status_changed();
// shopping
bool purchasable(int cost);
void purchase(int opt, Item item);
// random encounter
void percentage_damage(double percentage);
void percentage_restore(double percentage);
void looting_gold(int gold_);
void looting_exp(int exp_);
```
레벨업 함수들은 현재 status를 prev_status에 저장하고, curr_exp가 max_exp를 초과한다면 레벨업하여 정해진 스펙만큼 강화된다. 그러나 monster와의 전투 후 레벨업과 쇼핑 후 레벨업은 prev_curr_exp가 저장되는 시점이 다르고, “Level up!” 메시지를 출력 여부에서도 차이가 있기 때문에 overloading하여 분리해 구현하였다. 
 
몬스터를 공격하는 함수는 Monster::injured()를 호출하여 자신의 공격력(attack)을 넘기고, 실제 몬스터가 받은 피해를 반환받는다. 역으로 몬스터의 공격을 받을 경우에는 전달 받은 데미지에서 자신의 방어력만큼 경감된 피해량을 반환한다. 구현은 다음과 같다.
```c++
void attack_basic(Monster& enemy){
	int damage = enemy.injured(attack);
	std::cout << "You hit the monster with " << damage << " damage!" << std::endl;
}
int injured(int damage) {
	damage -= defense;
	curr_hp -= (damage < 0) ? 0 : damage;
	return damage;
}
```
만약 공격이 평타가 아닌 속성 기반 스킬로 수행된다면 curr_mp를 15 소모하여 속성에 맞는 Monster::injured_{attribute_name}()을 호출한다. 만약 소모할 mp가 부족하다면 공격을 수행하지 못한다. 
 
싸우는 도중 hp가 0 이하로 떨어지는지는 bool is_alive()가 체크한다. void show_character_status()는 자신의 status를 정해진 포맷으로 출력한다. 
 
만약 status 변화량을 확인하고 싶다면, 변화하기 전 status와 현재 status를 함께 출력하는 void show_character_status_changed()를 호출하면 된다. 주어진 과제요건에서는 menu의 fight()와 shopping()의 마지막에서 호출된다. bool purchasable(int cost)는 현재 예산(gold)가 비용(cost)를 넘는지 여부를 반환한다. menu의 shopping()에서 purchasable()을 통과하면 void purchase(int opt, Item item)가 호출되는데, 전달 받은 opt와 앞서 정의한 enum Items의 비교로 상승시킬 status를 찾아낸다. menu의 random_encounter()에서 호출하는 void percentage_damage(double percentage)와 void percentage_restore(double percentage)의 체력 비례 피해/회복량은 계산 결과가 정수로 떨어지지 않을 수 있기에 #define ROUND 0.5; 로 정의된 ROUND를 더해주어 int형으로 typecasting되면서 반올림 효과를 보도록 구현하였다.
### 2.3.4 
마지막 monster 클래스는 앞서 정의한 character 클래스의 일종의 하위집합이라고도 볼 수 있다. int attack, int defense, int attribute, int max_hp, int curr_hp, int reward 와 같이 유사한 member data를 가지고있고, member method 역시 유사한 면이 많다. Role이라는 base class 아래 character와 monster, 그리고 monster 밑에 boss라는 상속관계를 만들 수 있겠다. Member method는 다음과 같다. 
```c++
Monster(int difficulty);				// monster
Monster(int attack_, int defense_, int hp_);	// boss
// ~Monster();	// No need
int getReward();

void attack_basic(Character& gamer);
int injured(int damage);
int injured_skill(int damage);
int injured_fire(int damage);
int injured_grass(int damage);
int injured_water(int damage);

bool is_alive();
void show_monster_status();
```
유일한 getter는 Monster 처치 시 호출되는 getReward()이다. Menu의 fight()에서 Character::looting_gold()와 Character::looting_exp()가 반환된 reward 값을 전달 받는다. attack_basic()과 injured()는 character에서 구현된 바와 동일하다. 그러나 character에서 상술한 것처럼, character가 공격한 속성에 따라 호출되는 injured_{attribute_name}()이 다르다. 상성인 상성이라면 전달 받은 damage에 2배를 곱하여 다시 injured()함수를 호출한다. 코드는 다음과 같다.
```c++
int Monster::injured_fire(int damage) {
	if (attribute == GRASS)
		damage *= 2;
	return injured(damage);
}
```
실제 데미지 비교는 다음과 같다.
    
이때, GRASS를 비롯한 속성들은 enum Attribute { BASIC, NONE, GRASS, WATER, FIRE }; 에 의해 정의되었다. void show_monster_status() 역시 character처럼 정해진 포맷에 따라 status를 출력한다. 특이할 사항으로는 Monster/Boss 여부에 따라 호출되는 생성자가 다르다. 일반 Monster라면 map::distance()가 반환한 난이도(difficulty)에 의존하여 status가 정해진다. 이때, int형을 반올림하여 맞추기 위해 앞서 정의한 ROUND를 더해준다. 그러나 Boss는 고정된 스펙으로 정의된다. 둘 모두 속성은 rand()%4를 통해 랜덤으로 정해진다. 한편, Boss의 reward는 -1로 고정되어, menu의 fight()에서 게이머가 승리한 것이 Boss인지 아닌지 판별하는 기준이 된다.

# 3.	토론 및 개선
난이도에 특별한 어려움을 느끼진 않았다. 특히 Shop이 여러 번 재방문이 가능한 점이 난이도를 특출나게 낮춰준다. 최대 MP가 스킬을 5번 이상 쓸 수 있을 정도로만 레벨업을 마치면 Boss까지 무난하게 잡을만한 난이도였다. 밸런스 조절을 위해서라면 오히려 EMPTY를 아예 없애고, 중간 Boss를 하나나 둘 정도 Boss 위치 근처에 만들어 character가 움직일 대마다 한칸씩 돌아다니도록 만드는 것도 좋겠다. 너무 정적인 난이도라 2~3번 클리어하니 긴장감이 매우 떨어졌다.

상속관계를 사용하면 훨씬 간단하고, 짧게 구현할 수 있는 객체들(monster, character) 시험해보지 못해서 아쉽다. 과제 제출 후 따로 시도해봐야겠다.
사용자 편의성을 위해, show_character_status()에서 gold도 표기하는 것도 좋겠다. 현재 골드를 Shop에서 밖에 확인하지 못한다는 것이 불편했다. 한편 Map 상에서 Shop 위치를 확인하면 표기하는 것도 고려해볼만한 사항이다. Shop 위치가 랜덤으로 변경되거나 20% 확률로 random_encounter에서 등장하는 것도 재미있는 요소일 것 같다.

# 4.	참고 문헌
없음
