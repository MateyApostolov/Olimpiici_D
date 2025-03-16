#include <bits/stdc++.h>
using namespace std;

vector <int> s;
void raz (int num) {
    vector <int> r;
    while(num > 0) {
        r.push_back(num % 10);
        num /= 10;
    }
    for(int i = r.size() - 1; i >= 0; i--) s.push_back(r[i]);
    return;
}

int main () {
    int k;
    cin >> k;
    for(int i = 1; s.size() < k; i++) {
        int num = i * i * i;
        raz(num);
    }
    if(k % s.size() == 0) cout << s[s.size() - 1];
    else cout << s[k % s.size() - 1];
    return 0;
}
