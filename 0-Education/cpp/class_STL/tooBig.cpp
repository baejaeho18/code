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

template <typename T, typename Threshold>
void remove_if(std::list<T>& lst, Threshold pred) {
    for (auto it = lst.begin(); it != lst.end(); /* empty */) {
        if (pred(*it)) {
            it = lst.erase(it);
        }
        else {
            ++it;
        }
    }
}

bool tooBig(int n) { return n > 100; }

int main() {
    std::list<int> scores = { 100, 200, 300, 150, 250, 180 };

    scores.remove_if(TooBig<int>(200));
    for (int score : scores)
        std::cout << score << " ";
    std::cout << std::endl;

    remove_if(scores, TooBig<int>(150));
    for (int score : scores)
        std::cout << score << " ";
    std::cout << std::endl;

    scores.remove_if(tooBig);
    for (int score : scores)
        std::cout << score << " ";
    std::cout << std::endl;

    return 0;
}
