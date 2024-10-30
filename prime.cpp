#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> del;

bool is_prime (int num) {
    if(num < 2) return false;
    double koren = sqrt(num);
    for(int i = 2; i <= koren; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void kan_razlagane (int num) {
    int h = 2;
    map <int, int> mp;
    while(num > 1) {
        if(is_prime(num)) {
            mp[num]++;
            break;
        }
        if(is_prime(h)) {
            while(num % h == 0) {
                num /= h;
                mp[h]++;
            }
        }
        h++;
    }
    for(auto x : mp) {
        del.push_back({x.first, x.second});
    }
    return;
}

int main () {
    int n, j;
    cin >> n;
    kan_razlagane(n);
    int k = del.size();
    int r[k] = {};
    bool p[k] = {};
    while(true) {
        int d = 1;
        for(int i = 0; i < k; i++) {
            d *= pow(del[i].first, r[i]);
        }
        cout << d << ' ';
        for(j = 0; j < k; j++) {
            if(j != k && p[j]) {
                r[j]--;
                if(r[j] >= 0) break;
                else {
                    r[j] = 0;
                    p[j] = false;
                }
            } else {
                r[j]++;
                if(r[j] <= del[j].second) break;
                else {
                    r[j]--;
                    p[j] = true;
                }
            }
        }
        if(j >= k) return 0;
    }



    return 0;
}
