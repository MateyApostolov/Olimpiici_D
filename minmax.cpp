#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, s, c, l = 0, r;
    cin >> n >> s;
    map <int, int> mp;
    vector <pair<long long, int>> nums;
    for(int i = 0; i < n; i++) {
        cin >> c;
        mp[c]++;
    }
    for(auto x : mp) {
        nums.push_back({x.first, x.second});
    }
    r = nums.size() - 1;
    while(l < r) {
        long long hl = (nums[l + 1].first - nums[l].first) * nums[l].second;
        long long hr = (nums[r].first - nums[r - 1].first) * nums[r].second;
        if(nums[l].second > nums[r].second) {
            if(s > hr) {
                nums[r - 1].second += nums[r].second;
                s -= hr;
                r--;
            } else {
                nums[r].first -= s / nums[r].second;
                break;
            }
        } else {
            if(s > hl) {
                nums[l + 1].second += nums[l].second;
                s -= hl;
                l++;
            } else {
                nums[l].first += s / nums[l].second;
                break;
            }
        }
    }
    cout << nums[r].first - nums[l].first;
    return 0;
}
