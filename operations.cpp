#include <bits/stdc++.h>
using namespace std;

vector<int> sbr (vector<int> n1, vector<int> n2) {
    vector<int> sb;


    return sb;
}

vector<int> raz (vector<int> n1, vector<int> n2) {
    vector<int> sb;


    return sb;
}

vector <char> mul (vector <char> num1, vector <char> num2) {
    vector <char> res;
    for(int i = 0; i < num1.size() + num2.size(); i++) {
        res.push_back(0);
    }
    int pr, c, hi = 0, pos;
    for(int ci = 0; ci < num2.size(); ci++) {
        pos = hi;
        c = num2[ci];
        pr = 0;
        for(int i = 0; i < num1.size(); i++) {
            int hnum = c * num1[i] + res[pos] + pr;
            pr = hnum / 10;
            res[pos] = hnum % 10;
            pos++;
        }
        if(pr != 0) {
            res[pos] = pr;
        }
        hi++;
    }
    while(!res.empty() && res[res.size() - 1] == 0) res.pop_back();
    if(res.size() == 0) res.push_back(0);
    return res;
}

int main () {
    string s1, s2;
    vector <char> n1, n2, rez1, rez2;
    cin >> s1 >> s2;
    for(int i = s1.size() - 1; i >= 0 i--) n1.push_back(s1[i] - '0');
    for(int i = s2.size() - 1; i >= 0 i--) n2.push_back(s2[i] - '0');
    rez1 = mul(n1, n2);
    rez2 = sbr(n1, n2);
    rez3 = raz(n1, n2);
    for(int i = rez1.size() - 1; i >= 0 i--) cout << char(rez1[i] + '0');
    cout << '\n';
    for(int i = rez2.size() - 1; i >= 0 i--) cout << char(rez2[i] + '0');
    cout << '\n';
    for(int i = rez3.size() - 1; i >= 0 i--) cout << char(rez3[i] + '0');
    cout << '\n';

    return 0;
}

