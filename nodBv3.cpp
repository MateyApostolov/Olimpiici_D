#include <bits/stdc++.h>
using namespace std;

void print (vector <char>& n) {
    for(int i = n.size() - 1; i >= 0; i--) {
        cout << char(n[i] + '0');
    }
    return;
}

vector <char> sum (vector <char>& n1, vector <char>& n2) {
    vector <char> res;
    int pr = 0, cur;
    if(n1.size() < n2.size()) swap(n1, n2);
    for(int i = 0; i < n1.size(); i++) {
        if(i < n2.size()) cur = n1[i] + n2[i] + pr;
        else cur = n1[i] + pr;
        if(cur < 10) {
            pr = 0;
            res.push_back(cur);
        } else {
            pr = 1;
            res.push_back(cur - 10);
        }
    }
    if(pr != 0) res.push_back(pr);
    return res;
}

int main () {
    vector <char> pr, prp, cur;
    int n;
    cin >> n;
    pr.push_back(2);
    prp.push_back(1);
    for(int i = 2; i <= n; i++) {
        cur = sum(pr, prp);
        prp = pr;
        pr = cur;
    }
    print(prp);
    cout << ' ';
    print(pr);
    return 0;
}
