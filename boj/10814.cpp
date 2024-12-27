#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct User {
    int age;
    string name;
    int order;
};

bool compare(User u1, User u2) {
    if(u1.age == u2.age) {
        return u1.order < u2.order;
    }
    return u1.age < u2.age;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    vector<User> user;

    for(int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;

        user.push_back({age, name, i});
    }

    sort(user.begin(), user.end(), compare);

    for(User u : user) {
        cout << u.age << " " << u.name << "\n";
    }

    return 0;
}