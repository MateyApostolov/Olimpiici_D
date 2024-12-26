#include <bits/stdc++.h>
using namespace std;

vector <char> StoV (string& s) {
    vector <char> res;
    for(int i = s.size() - 1; i >= 0; i--) {
        res.push_back(s[i] - '0');
    }
    return res;
}

void print (vector <char>& v) {
    for(int i = v.size() - 1; i >= 0; i--) {
        cout << char(v[i] + '0');
    }
    cout << '\n';
    return;
}

void fix (vector <char>& v) {
    while(!v.empty() && v.back() == 0) v.pop_back();
    if(v.empty()) v.push_back(0);
    return;
}

bool is_smaller (vector <char>& n1, vector <char>& n2) {
    if(n1.size() < n2.size()) return true;
    if(n1.size() > n2.size()) return false;
    for(int i = n1.size() - 1; i >= 0; i--) {
        if(n1[i] < n2[i]) return true;
        if(n1[i] > n2[i]) return false;
    }
    return false;
}

vector <char> sum (vector <char>& n1, vector <char>& n2) {
    vector <char> res;
    int num, pr = 0;
    if(n1.size() < n2.size()) swap(n1, n2);
    for(int i = 0; i < n1.size(); i++) {
        if(i >= n2.size()) num = pr + n1[i];
        else num = pr + n1[i] + n2[i];
        res.push_back(num % 10);
        pr = num / 10;
    }
    if(pr != 0) res.push_back(pr);
    return res;
}

vector <char> sub (vector <char>& n1, vector <char>& n2) {
    vector <char> res;
    int num, pr = 0;
    for(int i = 0; i < n1.size(); i++) {
        if(i >= n2.size()) num = n1[i] - pr;
        else num = n1[i] - n2[i] - pr;
        if(num < 0) {
            num += 10;
            pr = 1;
        } else pr = 0;
        res.push_back(num % 10);
    }
    fix(res);
    return res;
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

vector <char> div (vector <char>& n1, vector <char>& n2, vector <char>& ost) {
    vector <char> res;
    int i = n1.size() - 1;
    while(i >= 0) {
        while(i >= 0 && is_smaller(ost, n2)) {
            ost.insert(ost.begin(), n1[i]);
            res.push_back(0);
            fix(ost);
            i--;
        }
        int x = 0;
        while(!is_smaller(ost, n2)) {
            x++;
            ost = sub(ost, n2);
        }
        res[res.size() - 1] = x;
    }
    reverse(res.begin(), res.end());
    fix(res);
    return res;
}

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    vector <char> v1 = StoV(s1), v2 = StoV(s2), v3 = sum(v1, v2), v4 = sub(v1, v2), v5 = mul(v1, v2), ost, v6 = div(v1, v2, ost);
    print(v3);
    print(v4);
    print(v5);
    print(v6);
    print(ost);
    vector <char> v7 = mul(v6, v2), v8 = sum(v7, ost), v9 = sub(v1, v8);
    print(v9);
    return 0;
}
