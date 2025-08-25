#include <bits/stdc++.h>
using namespace std;

const int maxn = 10e5 + 5;

int n, heap[maxn];

void push (int num) {
    heap[++n] = num;
    int idx = n;
    while(idx != 1) {
        int p = idx / 2;
        if(heap[p] > heap[idx]) {
            swap(heap[p], heap[idx]);
        } else return;
        idx = p;
    }
}

void pop() {
    swap(heap[1], heap[n]);
    n--;
    int idx = 1;
    while(idx * 2 + 1 <= n) {
        int ch1 = idx * 2;
        if(idx * 2 + 1 <= n && heap[ch1] > heap[ch1 + 1]) ch1++;
        if(heap[idx] > heap[ch1]) swap(heap[idx], heap[ch1]);
        else {
            return;
        }
        idx = ch1;
    }
}

int top() {
    if(n == 0) return 0 / 0;
    return heap[1];
}

int m, nc[maxn];

int main () {
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> nc[i];
    }
    for(int i = 1; i <= m; i++) {
        push(nc[i]);
    }
    for(int i = 1; i <= m; i++) {
        nc[i] = top();
        pop();
    }
    for(int i = 1; i <= m; i++) {
        cout << nc[i] << ' ';
    }
    return 0;
}
