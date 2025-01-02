#include <bits/stdc++.h>
using namespace std;

void print (vector <char>& n) {
    for(int i = n.size() - 1; i >= 0; i--) {
        cout << char(n[i] + '0');
    }
    cout << '\n';
    return;
}

void fix (vector <char>& v) {
    while(!v.empty() && v.back() == 0) v.pop_back();
    if(v.empty()) v.push_back(0);
    return;
}

vector <char> mul (vector <char>& n1, vector <char>& n2) {
    vector <char> res;
    for(int i = 0; i < n1.size() + n2.size(); i++) res.push_back(0);
    int num, pr = 0, x;
    for(int i = 0; i < n2.size(); i++) {
        for(x = 0; x < n1.size(); x++) {
            num = n1[x] * n2[i] + res[x + i] + pr;
            res[x + i] = num % 10;
            pr = num / 10;
        }
        res[x + i] = pr;
        pr = 0;
    }
    fix(res);
    return res;
}

vector <char> mul_long (vector <char>& n1, int l) {
    vector <char> res;
    int num, pr = 0;
    for(int i = 0; i < n1.size(); i++) {
        num = n1[i] * l + pr;
        pr = num / 10;
        res.push_back(num - pr * 10);
    }
    while(pr != 0) {
        int cur = pr;
        pr = cur / 10;
        res.push_back(cur - pr * 10);

    }
    return res;
}

int main () {
    long long n , sum = 0;
    cin >> n;
    vector <char> num;
    num.push_back(1);
    for(int i = 2; i <= n; i++) {
        num = mul_long(num, i);
      ///  if(i % 500 == 0)print(res);

    }
    for(int i = 0; i < num.size(); i++) {
        sum += num[i];
    }
    cout << sum;
    return 0;
}
