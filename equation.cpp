#include <bits/stdc++.h>
using namespace std;

string raz (string a, string b) {
    string result;
    bool pr = false;
    while(b.size() < a.size()) {
        b = '0' + b;
    }
    for(int i = a.size() - 1; i >= 0; i--) {
        if(pr) a[i]--;
        pr = false;
        if(a[i] < b[i]) {
            pr = true;
            a[i] += 10;
        }
        result = char(a[i] - b[i] + '0') + result;
    }
    return result;
}

int main () {
    long long a, as;
    string b, c, r, rez;
    cin >> a >> b >> c;
    r = raz(b, c);
    as = to_string(a).size();
    long long bc = stoll(r.substr(0, as));
    while(as <= r.size()) {
        if(bc < a) rez += '0';
        else rez += char(bc / a + '0');
        bc = (bc % a) * 10 + r[as] - '0';
        as++;
    }
    while(rez[0] == '0' && rez.size() > 1) {
        rez = rez.substr(1, rez.size() - 1);
    }
    cout << rez;
    return 0;
}
