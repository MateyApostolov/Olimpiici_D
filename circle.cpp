#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <int> nums;
    int n, k, ost = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    while(k <= nums.size()) {
        vector <int> newn;
        for(int i = 0; i < nums.size(); i++) {
            if((i + 1 + ost) % k == 0) continue;
            newn.push_back(nums[i]);
        }
        ost = nums.size() % k;
        nums = newn;
    }
    while(nums.size() > 1) {
        int h = k % nums.size() - ost;
        if(h <= 0) h += n;
        ost = nums.size() - h;
        vector <int> newn;
        for(int i = 0; i < nums.size(); i++) {
            if(h - 1 == i) continue;
            newn.push_back(nums[i]);
        }
        nums = newn;
    }
    cout << nums[0];
    return 0;
}
