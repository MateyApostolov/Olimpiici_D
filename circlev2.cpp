#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <int> nums;
    int n, k, h = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    while(h != nums.size()) {
        for(int i = 0; i < k - 1; i++) {
            nums.push_back(nums[h]);
            h++;
        }
        h++;
    }
    cout << nums[h - 1];
    return 0;
}
