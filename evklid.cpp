#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

pair <int , int> extev(int a , int b) {
    if(b == 0) return {1, 0};
    pair <int, int> p = extev(b, a % b);
    int x = p.second, y = p.first - (a / b) * p.second;

    return {x, y};
}


signed main () {
    int a, b, c, d;
    cin >> a >> b >> c;
    d = gcd(a, b);
    if(c % d != 0) {
        cout << "Impossible";
        return 0;
    }
    a /= d;
    b /= d;
    c /= d;
    pair <int, int> ans = extev(a, b);

    int x0 = ans.first * c;
    int y0 = ans.second * c;

    int tmin = ceil(-1.0 * -x0 / b);
    int tmax = floor(1.0 * y0 / a);

    int x1 = x0 + b * tmin;
    int y1 = y0 - a * tmin;

    int x2 = x0 + b * tmax;
    int y2 = y0 - a * tmax;
    cout << min(abs(x1) + abs(y1), abs(x2) + abs(y2));
    return 0;
}
