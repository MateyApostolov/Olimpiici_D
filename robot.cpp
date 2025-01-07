#include <bits/stdc++.h>
using namespace std;

int k, j, i;
unordered_map <string, bool> mp;

void rec_k (string st, int x, int y, int k) {
    k--;
    if(abs(j - x) + abs(i - y) > k) return;
    st = st + '(' + to_string(x) + ',' + to_string(y) + ')';
    if(k == 0) {
        if(x == j && y == i) mp[st] = true;
        ///cout << st << '\n';
        return;
    }
    rec_k(st, x + 1, y, k);
    rec_k(st, x - 1, y, k);
    rec_k(st, x, y + 1, k);
    rec_k(st, x, y - 1, k);
}

int main () {
    cin >> k >> j >> i;
    if((abs(i) + abs(j)) % 2 == k % 2) rec_k("", 0, 0, k + 1);
    cout << mp.size();
    return 0;
}
