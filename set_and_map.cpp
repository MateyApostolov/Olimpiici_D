#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

void learn_set() {
    set<int> s{-10, 7, 3, 2, 8, 5, 6, 100};
    s.insert(100000);
    s.insert(7);
    s.erase(100);
    s.erase(101); /// Nothing happens!
    cout << s.size() << '\n';
    for(int x : s) cout << x << ' ';
    cout << '\n';

    cout << *s.begin() << ' ' << *(--s.end()) << '\n';

    if(s.find(9) == s.end()) cout << "9 does not exist in this set!\n";
    else cout << "9 exists\n";
    if(s.find(8) == s.end()) cout << "8 does not exist in this set!\n";
    else cout << "8 exists\n";

    multiset <int> ms(s.begin(), s.end());
    ms.insert(-10);
    ms.insert(-10);
    ms.insert(7);
    ms.insert(3);

    cout << ms.size() << '\n';
    for(int x : ms) cout << x << ' ';
    cout << '\n';

    ms.erase(-10);
    cout << ms.size() << '\n';
    cout << *ms.erase(ms.find(7)) << '\n';
    cout << ms.size() << '\n';

    cout << ms.count(3) << '\n';
    cout << distance(ms.lower_bound(3), ms.upper_bound(3)) << '\n';

    //auto == multiset<int>::iterator
    for(auto it = ms.lower_bound(1); it != ms.lower_bound(10); ++it) {
        cout << *it << ' ';
    }
    cout << '\n' << '\n';
}

void learn_map() {
    map<int, int> m;
    m[1] = 7;
    m[5] = 6;
    m[1] = 8;
    m.insert({2, 3}); // m[2] = 3
    m[-5] = -6;
    for(auto xy : m) {
        cout << '(' << xy.first << ',' << xy.second << ')' << '\n';
    }

    /// Bad idea cuz size increases!
    /*if(m[3] != 0) cout << "3 exists!\n";
    else cout << "3 does not exist!\n";
    cout << m.size() << '\n';*/

    cout << (m.count(3) != 0 ? "exists\n" : "does not exist\n");

    m.erase(1);
    m.erase(-1);
    cout << m.size() << '\n';

    for(auto [x, y] : m) {
        cout << '(' << x << ',' << y << ')' << '\n';
    }
    // auto == map<int, int>::iterator
    for(auto it = m.lower_bound(1); it != m.lower_bound(6); ++it) {
        cout << "(" << it->first << ", " << it->second << "), ";
    }
    cout << '\n';

    multimap <int, int> mm(m.begin(), m.end());
    cout << mm.begin()->first << ' ' << (--mm.end())->first << '\n';

    mm.insert({3, 1});
    mm.insert({3, 2});

    for(auto [x, y] : mm) {
        cout << '(' << x << ',' << y << ')' << '\n';
    }
}

int main () {
    learn_set();
    learn_map();

    return 0;
}
