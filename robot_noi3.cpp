#include <bits/stdc++.h>
using namespace std;

const int maxn = 22;
char s[maxn][maxn];
int br[maxn][maxn];

int main () {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int x = 1; x <= m; x++) {
            cin >> s[i][x];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int x = 1; x <= m; x++) {
            if(s[i][x + 1] == '.') br[i][x]++;
            if(s[i + 1][x] == '.') br[i][x]++;
            if(s[i - 1][x] == '.') br[i][x]++;
            if(s[i][x - 1] == '.') br[i][x]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int x = 1; x <= m; x++) {
            if(br[i][x] == 1) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}
