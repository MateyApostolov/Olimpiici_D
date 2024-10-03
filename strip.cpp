#include <iostream>
using namespace std;

const int maxc = 1000;
int br[maxc];

int main () {
    int n, r = -1, maxd = 0, dif = 0, x = 0, y = 0;
    cin >> n;
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    for(int i = 0; i < n; i++) {
        while(r + 1 < n && !(dif == 2 && br[nc[r + 1]] == 0)) {
            ///cout << r + 1 << " " << nc[r] << "\n";
            if(br[nc[r + 1]] == 0) {
                dif++;
            }
            br[nc[r + 1]]++;
            r++;
        }
        if(x - y + 1 < r - i + 1) {
            x = r + 1;
            y = i + 1;
        }
        ///cout << i + 1 << " " << r + 1 << " " << dif <<"\n";
        br[nc[i]]--;
        if(br[nc[i]] == 0) dif--;
    }
    cout << y << " " << x - y + 1;
    return 0;
}
