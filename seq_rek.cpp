#include <bits/stdc++.h>
using namespace std;

const int maxk = 51;
bool used[maxk];
int mp[maxk][maxk], dp[maxk][maxk];
vector <int> seq;

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
    if(seq.size() == n && is_bigger(seq)) {
        ///print(seq);
        br++;
    }
    for(int i = 1; i <= k; i++) {
        if(used[i]) continue;
        seq.push_back(i);
        used[i] = true;
        rec_seq();
        seq.pop_back();
        used[i] = false;
    }
}

int F (int k, int n) {
    if(n == 1) return k;
    if(n == k) return 1;
    if(n > k) return 0;
    return F(k - 1, n - 1) + F(k - 1, n);
}

int Fm (int k, int n) {
    if(mp[k][n] != -1) return mp[k][n];
    if(n == 1) return k;
    if(n == k) return 1;
    if(n > k) return 0;
    return Fm(k - 1, n - 1) + Fm(k - 1, n);
}

int main () {
   /*cin >> k >> n;
    rec_seq();
    cout << br;*/
    for(n = 1; n <= 10; n++) {
        for(k = 1; k <= 10; k++) {
            for(int j = 0; j < maxk; j++) used[j] = false;
            br = 0;
            seq.clear();
            rec_seq();
            cout << setw(4) << br;
        }
        cout << '\n';
    }
    cout << '\n';
    for(n = 1; n <= 10; n++) {
        for(k = 1; k <= 10; k++) {
            cout << setw(4) << F(k, n);
        }
        cout << '\n';
    }
    cout << '\n';
    for(n = 1; n <= 10; n++) {
        for(k = 1; k <= 10; k++) {
            for(int j = 0; j < maxk; j++) {
                for(int i = 0; i < maxk; i++) {
                    mp[j][i] = -1;
                }
            }
            cout << setw(4) << Fm(k, n);
        }
        cout << '\n';
    }
    cout << '\n';
    for(n = 1; n <= 10; n++) {
        for(k = 1; k <= 10; k++) {
            if(n == 1) dp[n][k] = k;
            else dp[n][k] = dp[n][k - 1] + dp[n - 1][k - 1];
            cout << setw(4) << dp[n][k];
        }
        cout << '\n';
    }
    return 0;
}
