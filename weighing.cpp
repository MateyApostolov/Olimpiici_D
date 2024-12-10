#include <bits/stdc++.h>
using namespace std;

vector <int> tri(int num) {
    vector <int> res;
    while(num > 0) {
        res.push_back(num % 3);
        num /= 3;
    }
    return res;
}

int my_pow (int num, int st) {
    return pow(num, st);
}

int main () {
    int n;
    char s;
    cin >> s >> n;
    vector <int> res = tri(n), v1, v2;
    for(int i = 0; i < res.size(); i++) {
        if(res[i] == 1) {
            v1.push_back(i);
        }
        if(res[i] == 2) {
            v2.push_back(i);
            int h = i + 1;
            bool t = true;
            while(h < res.size()) {
                if(res[h] < 2) {
                    res[h]++;
                    t = false;
                    break;
                } else {
                    res[h] = 0;
                    h++;
                }
            }
            if(t) {
                res.push_back(1);
            }
        }
    }
    if(s == 'L') {
        swap(v1, v2);
    }
    cout << "L:";
    for(int i = 0; i < v1.size(); i++) {
        cout << my_pow(3, v1[i]) << ' ';
    }
    cout << "\nR:";
    for(int i = 0; i < v2.size(); i++) {
        cout << my_pow(3, v2[i]) << ' ';
    }
    return 0;
}
