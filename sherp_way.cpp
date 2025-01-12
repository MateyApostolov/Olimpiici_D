#include <bits/stdc++.h>
using namespace std;

void sherp_way (int n, string s) {
    string news;
    if(n == 1) {
        cout << s;
        return;
    } else {
        sherp_way(n - 1, s);
        for(int i = 0; i < s.size(); i++) {
            news += "O";
        }
        sherp_way(n - 1, news);
        sherp_way(n - 1, s);
    }
}

int main () {
    int n;
    cin >> n;
    sherp_way(n, "XOX");

    return 0;
}
