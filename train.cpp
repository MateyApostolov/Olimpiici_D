#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, qc;
    cin >> n;
    for(int i = 0; i < 5; i++) {
        stack <int> c;
        queue <int> nr, qr;
        for(int x = 1; x <= n; x++) nr.push(x);
        for(int x = 1; x <= n; x++) {
            cin >> qc;
            qr.push(qc);
        }
        while(!nr.empty()) {
            c.push(nr.front());
            nr.pop();
            while(!c.empty() && c.top() == qr.front()) {
                c.pop();
                qr.pop();
            }
        }
        if(qr.empty()) cout << 1;
        else cout << 0;
    }

    return 0;
}
