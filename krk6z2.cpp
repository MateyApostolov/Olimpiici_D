#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
int s1[3][maxn], s2[3][maxn], r[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, q, x, y;
    cin >> n >> q;
    string c1, c2;
    cin >> c1 >> c2;
    if(c1[0] == 'A') {
        s1[0][0]++;
    }
    if(c1[0] == 'C') {
        s1[1][0]++;
    }
    if(c1[0] == 'T') {
        s1[2][0]++;
    }
    if(c2[0] == 'A') {
        s2[0][0]++;
    }
    if(c2[0] == 'C') {
        s2[1][0]++;
    }
    if(c2[0] == 'T') {
        s2[2][0]++;
    }
    if(c1[0] != c2[0]) {
        r[0]++;
    }
    for(int i = 1; i < n; i++) {
        if(c1[i] == 'A') {
            s1[0][i] = s1[0][i - 1] + 1;
        }
        if(c1[i] == 'C') {
            s1[1][i] = s1[1][i - 1] + 1;
        }
        if(c1[i] == 'T') {
            s1[2][i] = s1[2][i - 1] + 1;
        }
        if(c2[i] == 'A') {
            s2[0][i] = s2[0][i - 1] + 1;
        }
        if(c2[i] == 'C') {
            s2[1][i] = s2[1][i - 1] + 1;
        }
        if(c2[i] == 'T') {
            s2[2][i] = s2[2][i - 1] + 1;
        }
        if(c1[i] != c2[i]) {
            r[i] = r[i - 1] + 1;
        }
    }
    for(int i = 0; i < q; i++) {
        cin >> x >> y;
        int A, C, T, R;
        if(x == 0) {
            A = s1[0][y] - s2[0][y];
            C = s1[1][y] - s2[1][y];
            T = s1[2][y] - s2[2][y];
            R = r[y];
        } else {
            A = s1[0][y] - s1[0][x - 1] - (s2[0][y] - s2[0][x - 1]);
            C = s1[1][y] - s1[1][x - 1] - (s2[1][y] - s2[1][x - 1]);
            T = s1[2][y] - s1[2][x - 1] - (s2[2][y] - s2[2][x - 1]);
            R = r[y] - r[x - 1];
        }
        if(A == 0 && C == 0 && T == 0) {
            cout << R / 2 << '\n';
        } else {
            cout << -1 << A << " " << C << " " << T << '\n';
        }
    }

    return 0;
}

