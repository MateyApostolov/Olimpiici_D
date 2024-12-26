#include <bits/stdc++.h>
using namespace std;

string sbor (string n1, string n2) {
    string sb;
    int p1 = n1.size() - 1, p2 = n2.size() - 1, ost = 0;
    while(p1 >= 0 || p2 >= 0) {
        int c1 = n1[p1] - '0', c2 = n2[p2] - '0';
        if(p1 < 0) {
            c1 = 0;
        }
        if(p2 < 0) {
            c2 = 0;
        }
        int temp = c1 + c2 + ost;
        sb += temp % 10 + '0';
        ost = temp / 10;
        p1--;
        p2--;
    }
    if(ost != 0) {
        sb += '1';
    }
    reverse(sb.begin(), sb.end());
    return sb;
}

vector <char> mul (vector <char> num1, vector <char> num2) {
    vector <char> res;
    for(int i = 0; i < num1.size() + num2.size(); i++) {
        res.push_back(0);
    }
    int pr, c, hi = 0, pos;
    for(int ci = num2.size() - 1; ci >= 0; ci--) {
        pos = hi;
        c = num2[ci];
        pr = 0;
        for(int i = num1.size() - 1; i >= 0; i--) {
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
    while(!res.empty() && res[res.size() - 1] == 0) {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    if(res.size() == 0) res.push_back(0);
    return res;
}

string sb (string s, int os) {
    string sum;
    vector <char> st, brs;
    st.push_back(1);
    while(os > 0) {
        brs.push_back(os % 10);
        os /= 10;
    }
    reverse(brs.begin(), brs.end());
///    for(int i = 0; i < brs.size(); i++) cout << char(brs[i] + '0') << ' '; cout << '\n';
    for(int i = 0; i < s.size(); i++) {
        vector <char> um, c;
        if(i != 0) st = mul(st, brs);
        if(isdigit(s[i])) {
            c.push_back(s[i] - '0');
        } else {
            int h = s[i] - 'A' + 10;
            while(h > 0) {
                c.push_back(h % 10);
                h /= 10;
            }
        }
        reverse(c.begin(), c.end());
///        for(int i = 0; i < c.size(); i++) cout << char(c[i] + '0') << ' '; cout << '\n';
        c = mul(c, st);
///        for(int i = 0; i < c.size(); i++) cout << char(c[i] + '0') << ' '; cout << '\n';
        string newc;
        for(int i = 0; i < c.size(); i++) {
            newc += char(c[i] + '0');
        }
        sum = sbor(sum, newc);
    }
    return sum;
}

int main () {
/*    string s1, s2;
    vector <char> n1, n2, rez;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) n1.push_back(s1[i] - '0');
    for(int i = 0; i < s2.size(); i++) n2.push_back(s2[i] - '0');
    rez = mul(n1, n2);
    for(int i = 0; i < rez.size(); i++) {
        cout << char(rez[i] + '0');
    }
    string ttt = sbor(s1, s2);
    cout << '\n' << ttt;
    return 0; */

    int n;
    string s, num;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    num = sb(s, n);
    cout << num;
    return 0;
}

