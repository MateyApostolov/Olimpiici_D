#include <bits/stdc++.h>
using namespace std;

const int maxn = 200001;
int pozn2[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, br = 0, brk;
    cin >> n;
    brk = n;
    int r1[n], r2[n];
    bool p[n] = {};
    for(int i = 0; i < n; i++) {
        cin >> r1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> r2[i];
        pozn2[r2[i]] = i;
    }
    for(int i1 = 1; i1 < n; i1++) {
        br = 0;
        if(pozn2[r1[i1 + br - 1]] + 1 == pozn2[r1[i1 + br]]) {
            brk--;
        }
        ///cout << brk << "\n";
    }
    cout << brk;
    return 0;
}
