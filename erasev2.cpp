#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <int> nums;
    int n, q, qc;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    for(int i = 0; i < q; i++) {
        cin >> qc;
        vector <int> newn;
        for(int i = 0; i < nums.size(); i++) {
            if(i != qc - 1) {
                newn.push_back(nums[i]);
            }
        }
        nums = newn;
    }
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}