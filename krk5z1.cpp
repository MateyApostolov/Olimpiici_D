#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, br = 0, r = 1;
    cin >> n;
    string s;
    vector <string> nums;
    for(int i1 = 0; i1 < n; i1++) {
        cin >> s;
        sort(s.begin(), s.end());
        nums.push_back(s);
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            r++;
        } else {
            br += (r * (r - 1)) / 2;
            r = 1;
        }
    }
    if(br != 1) {
        br += (r * (r - 1)) / 2;
    }
    cout << br;
    return 0;
}
