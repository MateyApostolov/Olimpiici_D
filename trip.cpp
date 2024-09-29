#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000000;

int main () {
    long long n, m, nmsum, izi;
    cin >> n >> m;
    int nc[maxn];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    /*for(int i = 0; i < n; i++) {
        long long br = 0, sum = 0;
        while(i + br < n && br < m) {
            sum += nc[i + br];
            br++;
        }
        if(i == 0) {
            nmsum = sum;
            izi = i;
        }
        if(sum < nmsum) {
            nmsum = sum;
            izi = i;
        }
    }*/
    cout << izi;

    return 0;
}
