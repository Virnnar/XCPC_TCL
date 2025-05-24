#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 5E5 + 6;

int n, L, R;
ll h[N];

bool check(ll mid) {
    ll res = 0;
    for (int i = 1; i <= n; i++) res += min(mid, h[i]);
    return res >= L * mid;
}

int main() {
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) h[i] = (h[i] - 1) / 2;
    sort(h + 1, h + n + 1);
    ll l = 0, r = 1E12;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    puts(n <= R + l * (R - L) ? "Yes" : "No");
}

