    #include <bits/stdc++.h>
    using namespace std;

    long long l, g;
    vector <int> del;
    void find_del(int num) {
        int i;
        for(i = 2; i * i < num; i++) {
            if(num % i == 0) {
                del.push_back(num / i);
                del.push_back(i);
            }
        }
        if(num % i == 0) {
            del.push_back(i);
        }
    }

    int main () {
        cin >> l >> g;
        for(int i = 0; i < del.size(); i++) {

        }

        return 0;
    }

