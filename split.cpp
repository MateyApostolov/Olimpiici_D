#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nc;
    long long sum = 0;
    cin >> n;
    vector <int> odd, even;
    for(int i = 0; i < n * 2; i++) {
        cin >> nc;
        if(nc % 2 == 0) {
            even.push_back(nc);
        } else {
            odd.push_back(nc);
        }
    }
    for(int i = 0; i < n; i++) {
        sum += (long long)abs(even[i] - odd[i]);
    }
    cout << sum;
    return 0;
}
