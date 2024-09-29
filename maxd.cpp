#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000, maxc = 100000;
int brc[maxc];

int main () {
    int n;
    cin >> n;
    int nc[maxn], ngbr = 0, izl;
    vector <int> ngr;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int l = 0, r = -1; l < n;) {
        while(r < n && brc[nc[r + 1]] == 0) {
            r++;
            brc[nc[r]]++;
        }
        int br = r - l + 1;
        if(br > ngbr) {
            izl = l;
            ngbr = br;
        }
        brc[nc[l]] = 0;
        l++;
    }
    cout << ngbr << '\n';
    for(int i = izl; i < izl + ngbr; i++) {
        cout << nc[i] << ' ';
    }
    return 0;
}
