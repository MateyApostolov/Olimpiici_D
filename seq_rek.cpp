#include <bits/stdc++.h>
using namespace std;

const int maxk = 51;
bool used[maxk];
vector <int> seq;
map <vector <int>, bool> mp;

int k, n, br;

void print (vector <int> seq) {
    for(int i = 0; i < seq.size(); i++) {
        cout << seq[i];
    }
    cout << '\n';
    return;
}

bool is_bigger (vector <int> seq) {
    for(int i = 1; i < seq.size(); i++) {
        if(seq[i] < seq[i - 1]) return false;
    }
    return true;
}

void rec_seq() {
    if(mp[seq]) return;
    if(seq.size() == n && is_bigger(seq) && mp.find(seq) != mp.end()) {
        print(seq);
        br++;
        mp[seq] = true;
        seq.empty();
        used[maxk] = {};
    }
    for(int i = 1; i <= k; i++) {
        if(used[i]) continue;
        seq.push_back(i);
        used[i] = true;
        rec_seq();
        seq.pop_back();
        used[i] = false;
    }
    return;
}

int main () {
    cin >> k >> n;
    rec_seq();
    cout << br;
    return 0;
}
