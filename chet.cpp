#include <bits/stdc++.h>
using namespace std;

int main () {
    string num;
    cin >> num;
    if(num == "1") {
        cout << 0;
        return 0;
    }
    bool t = true;
    for(int i = 0; i < num.size(); i++) {
        if((num[i] - '0') % 2 != 0) t = false;
    }
    if(t) {
        for(int i = num.size() - 1; i >= 0; i--) {
            if(num[i] != '0') {
                num[i] -= 2;
                break;
            } else {
                num[i] = '8';
            }
        }
        if(num[0] == '0') cout << num.substr(1, num.size() - 1);
        else cout << num;
        return 0;
    }
    for(int i = 0; i < num.size(); i++) {
        if((num[i] - '0') % 2 != 0) {
            if(num[i] == '1' && i == 0) {
                for(int x = 1; x < num.size(); x++) cout << 8;
                return 0;
            }
            cout << (num[i] - '0') - 1;
            for(int x = i + 1; x < num.size(); x++) cout << 8;
            return 0;
        }
        cout << num[i];
    }

    return 0;
}
