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

int main () {
    string n1, n2, res;
    cin >> n1 >> n2;
    res = sbor(n1, n2);
    cout << res;

    return 0;
}
