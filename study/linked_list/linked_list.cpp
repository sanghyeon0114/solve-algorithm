#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> li = {0, 0, 0, 0, 0};
    list<int> li2(5);
    list<int> li3(5, 0);

    list<int>::iterator cur = li.begin();

    cur++;

    li.push_back(1);
    li.push_front(2);

    li.insert(cur, 5);

    return 0;
}