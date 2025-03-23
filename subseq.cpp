#include <bits/stdc++.h>
using namespace std;

vector <long long> seq;

void razlagane (long long num) {
    vector <long long> help;
    while(num > 0) {
        help.push_back(num % 10);
        num /= 10;
    }
    for(long long i = help.size() - 1; i >= 0; i--) {
        seq.push_back(help[i]);
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long m, k, s, mincl, r = -1, sum = 0, brw = 0;
    cin >> m >> k >> s;
    mincl = s;
    vector <long long> news;
    for(long long i = 1; i <= m; i++) {
        razlagane(i);
    }
    for(long long i = 1; i <= seq.size(); i++) {
        long long help = 0;
        while(i <= seq.size() && i % k != 0) {
            help = help * 10 + seq[i - 1];
            i++;
        }
        if(help == 0) continue;
        news.push_back(help);
    }
    for(int i = 0; i < news.size(); i++) cout << news[i] << ' ';
    cout << '\n';
    for(int l = 0; l < news.size(); ) {
        while(r + 1 < news.size() && sum > s - mincl && sum < s + mincl) {
            r++;
            sum += news[r];
        }
        if(abs(s - sum) < mincl) {
            brw = 0;
            mincl = abs(s - sum);
        }
        if(abs(s - sum) == s - mincl || abs(s - sum) == s + mincl) brw++;
        l++;
        sum -= news[l];
    }
    cout << brw;
    return 0;
}

