#include <iostream>
#include <list>
#include <algorithm>

template<class T>
class TooBig {
private:
    T cutoff;
public:
    TooBig(const T& t) : cutoff(t) {}
    bool operator() (const T& v) { return v > cutoff; }
};

int main() {
    std::list<int> scores = { 100, 200, 300, 150, 250, 180 };

    scores.remove_if(TooBig<int>(200));

    for (int score : scores) {
        std::cout << score << " ";
    }

    return 0;
}
