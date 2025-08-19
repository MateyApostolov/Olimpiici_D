#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, nc, hi = 0;
    cin >> n;
    stack <int> gift, help;
    vector <int> gift3, ans;
    for(int i = 1; i <= n; i++) {
        cin >> nc;
        gift.push(i);
        gift3.push_back(nc);
    }
    while(hi < n) {
        if(help.empty()) {
            help.push(gift.top());
            gift.pop();
            ans.push_back(1);
            continue;
        }
        if(help.top() == gift3[hi]) {
            help.pop();
            ans.push_back(2);
        } else {
            if(gift.empty()) {
                gift.push(help.top());
                help.pop();
                ans.push_back(3);
            } else {
                help.push(gift.top());
                gift.pop();
                ans.push_back(1);
                continue;
            }
        }

        hi++;
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}
