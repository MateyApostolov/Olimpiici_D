#include <bits/stdc++.h>
using namespace std;

bool brbw[26];

int main () {
    brbw['J' - 'A'] = true;
    string w, q, oldq, ans, onlyb;
    char kvw[5][5], lw[25];
    getline(cin, w);
    getline(cin, oldq);
    for(int i = 0; i < w.size(); i++) {
        if(w[i] == 'J') {
            w[i] = 'I';
        }
    }
    ///cout << w << '\n';
    for(int i = 0; i < oldq.size(); i++) {
        if(oldq[i] == 'J') {
            oldq[i] = 'I';
        }
    }
    int hi = 0;
    for(int i = 0; i < w.size(); i++) {
        if(brbw[w[i] - 'A']) continue;
        brbw[w[i] - 'A'] = true;
        lw[hi] = w[i];
        hi++;
    }
    for(int i = 0; i < 26; i++) {
        if(!brbw[i]) {
            lw[hi] = char(i + 'A');
            hi++;
        }
    }
    for(int i = 0; i < 25; i++) {
        kvw[i / 5][i % 5] = lw[i];
    }
    for(int i = 0; i < oldq.size(); i++) {
        if(!isalpha(oldq[i])) continue;
        onlyb += oldq[i];
    }
    oldq = onlyb;
    q = oldq[0];
    for(int i = 1; i < oldq.size(); i++) {
        if(oldq[i - 1] == oldq[i] && oldq[i] == 'Q') {
            q = q + 'Z';
        } else if(oldq[i - 1] == oldq[i]) {
            q = q + 'Q';
        }
        q = q + oldq[i];
    }
    if(q.size() % 2 != 0) {
        if(q[q.size() - 1] == 'Q') {
            q += 'Z';
        } else {
            q += 'Q';
        }
    }
    map <pair<int, int>, char> korc;
    map <char, pair<int, int>> ckor;
    for(int r = 0; r < 5; r++) {
        for(int k = 0; k < 5; k++) {
            korc[{r, k}] = kvw[r][k];
            ckor[kvw[r][k]] = {r, k};
        }
    }
    for(int i = 0; i < q.size(); i += 2) {
        int r1 = ckor[q[i]].first, k1 = ckor[q[i]].second;
        int r2 = ckor[q[i + 1]].first, k2 = ckor[q[i + 1]].second;
        pair <int, int> v1, v2;
        if(k1 == k2) {
            v1 = {(r1 + 1) % 5, k1};
            v2 = {(r2 + 1) % 5, k2};
        } else if(r1 == r2) {
            v1 = {r1, (k1 + 1) % 5};
            v2 = {r2, (k2 + 1) % 5};
        } else {
            v1 = {r1, k2};
            v2 = {r2, k1};
        }
        ans += korc[v1];
        ans += korc[v2];
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i % 2 != 0) {
            cout << ' ';
        }
    }
    return 0;
}
