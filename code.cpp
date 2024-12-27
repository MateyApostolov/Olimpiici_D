#include <bits/stdc++.h>
using namespace std;

const int maxs = 50;
int n, brc;
char num[maxs];
bool used[maxs];

void print (char num[maxs]){
    for(int i = 0; i < maxs; i++) cout << num[i];
    cout << '\n';
}

void solve (char num[maxs]) {
    brc++;
    cout << brc << ' ';
    print(num);
    char newn[maxs];
    for(int i = 0; i < maxs - 1; i++) {
        if(used[i]) continue;
        newn[i] = num[i];
        if(!isdigit(num[i]) || !isdigit(num[i + 1])) continue;
        int nc = (num[i] - '0') * 10 + num[i + 1] - '0';
        if(nc >= 10 + n || nc < 10) continue;
        newn[i] = char(nc - 10 + 'a');
        used[i] = true;
        i++;
        newn[i] = ' ';
        used[i] = true;
        for(int x = i + 1; x < maxs; x++) newn[x] = num[x];
        solve(newn);
        newn[i] = num[i];
        used[i] = false;
        newn[i - 1] = num[i - 1];
        used[i - 1] = false;
    }
    return;
}

int main () {
    char c;
    cin >> n;
    int h = 0;
    while(cin >> c) {
        h++;
        num[h] = c;
    }
    cout << "ahdgsvsdfsydfdash\n";
    solve(num);
    cout << brc;
    return 0;
}
