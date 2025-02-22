#include <bits/stdc++.h>
using namespace std;

int main () {
    string st;
    getline(cin, st);
    vector <char> num;
    int hi = 0, d = 0, s = 0, beg = 0, step;
    for(int i = 0; i < st.size(); i++) num.push_back(st[i]);
    for(int i = 0; isdigit(num[i]); i++) d = d * 10 + (9 - (num[i] - '0'));
    for(int i = num.size() - 1; isdigit(num[i]); i--) s = s + (9 - (num[i] - '0')) * pow(10, num.size() - 1 - i);
    while(isdigit(num[0])) num.erase(num.begin());
    while(isdigit(num.back())) num.pop_back();
    int red[d];
    step = num.size() / d;
    for(int i = 0; i < d; i++) red[i] = step;
    for(int i = 0; i < num.size() % d; i++) red[i]++;
    beg = red[0];
    if(s != 1) {
        for(int i = s - 1; i < d; i++) beg += red[i];
    }
    ///for(int i = 0; i < num.size(); i++) cout << num[i];
    while(hi < num.size()) {
        cout << num[beg - 1];
        hi++;
        beg = (beg + step) % num.size();
    }
    return 0;
}
