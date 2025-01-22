#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000000;
int min_del[maxn], adel[maxn], bdel[maxn];

void eratosten (int n) {
    for(long long d = 2; d <= n; d++) {
        if(min_del[d] > 0) continue;
        for(long long k = d; k <= n; k += d) {
            if(min_del[k] == 0) min_del[k] = d;
        }
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, a, b;
    cin >> n >> q;
    eratosten(n);
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        int res = 1, ha = a, hb = b;
        unordered_map <int, int> del;
        while(ha > 1) {
            del[min_del[ha]]++;
            ha /= min_del[ha];
        }
        while(hb > 1) {
            del[min_del[hb]]++;
            hb /= min_del[hb];
        }
        for(auto x : del) {
            res *= pow(x.first, x.second / 2);
        }
        cout << res << ' ';
    }

    return 0;
}
