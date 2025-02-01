#include <bits/stdc++.h>
using namespace std;

const int maxh = 101, maxn = pow(10, 5) + 1;
int hst[maxh];
bool upst[maxn];

int main () {
    int n, t;
    cin >> n >> t;
    int height[n];
    vector <pair<int, int>> st;
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }
    for(int i1 = 0; i1 < n - 1; i1++) {
        for(int i2 = i1 + 1; i2 < n; i2++) {
            if(height[i1] < height[i2]) break;
            if(height[i1] == height[i2]) {
                st.push_back({i1, i2});
                break;
            }
        }
    }
    if(t == 1) {
        cout << st.size();
        return 0;
    }
    int top[st.size()] = {}, brst = 0;
    for(int i1 = 0; i1 < st.size() - 1; i1++) {
        for(int i2 = i1 + 1; i2 < st.size(); i2++) {
            if(st[i1].second > st[i2].first) {
                brst++;
                break;
            }
            if(st[i1].second < st[i2].first) break;
        }
    }
    cout << brst;
    return 0;
}
