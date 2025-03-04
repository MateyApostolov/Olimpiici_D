#include <bits/stdc++.h>
using namespace std;

int main () {
    int s, m, h, k, brd = 0;
    cin >> s >> m >> h >> k;
    stack <int> S, M, H;
    queue <int> K;
    for(int i = 1; i <= k; i++) K.push(i);
    while(true) {
        if(S.size() < s) {
            S.push(K.front());
            K.pop();
        }
        if(S.size() == s) {
            M.push(S.top());
            S.pop();
            while(!S.empty()) {
                K.push(S.top());
                S.pop();
            }
        }
        if(M.size() == m) {
            H.push(M.top());
            M.pop();
            while(!M.empty()) {
                K.push(M.top());
                M.pop();
            }
        }
        if(H.size() == h) {
            brd++;
            while(!H.empty()) {
                K.push(H.top());
                H.pop();
            }
        }
        bool t = true;
        for(int i = 1; i <= K.size(); i++) {
            if(K.front() != i) {
                t = false;
            }
            K.push(K.front());
            K.pop();
        }
        if(t) {
            cout << brd;
            break;
        }
    }

    return 0;
}
