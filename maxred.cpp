#include <bits/stdc++.h>
using namespace std;

string upravi_mi_chisloto (string num, int k) {
    string res(num.size() - k, '0');
    stack <char> st;
    int brsk = 0, hi = res.size();
    for(int i = 0; i < num.size(); i++) {
        while(brsk < k && !st.empty() && num[i] > st.top()) {
            st.pop();
            brsk++;
        }
        st.push(num[i]);
    }
    for(int i = 0; i < k - brsk; i++) st.pop();
    while(!st.empty()) {
        res[hi] = st.top();
        st.pop();
        hi--;
    }

    return res;
}

int main () {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << upravi_mi_chisloto(s.substr(0, n), k) << upravi_mi_chisloto(s.substr(n, n), k) << upravi_mi_chisloto(s.substr(2 * n, n), k);

    return 0;
}
