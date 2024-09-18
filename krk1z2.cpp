#include <bits/stdc++.h>
using namespace std;

vector <long long> alldel;

void find_del (long long num) {
    int i;
    for(i = 1; i * i < num; i++) {
        if(num % i == 0) {
            alldel.push_back(i);
            alldel.push_back(num / i);
        }
    }
    if(i * i == num) {
        alldel.push_back(i);
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, q, qnum;
    cin >> n >> q;
    find_del(n);
    sort(alldel.begin(), alldel.end());
    for(int i = 0; i < q; i++) {
        cin >> qnum;
        int h = 0;
        while(alldel[h] < qnum) {
            h++;
        }
        cout << alldel[h] << "\n";
    }

    return 0;
}
