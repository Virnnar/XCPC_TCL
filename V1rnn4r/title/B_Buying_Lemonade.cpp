#include "Monday.h"

using namespace virmar;

void doit() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
        b[i] = (a[i] - a[i - 1]) * (n - i + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        if (sum + b[i] >= k)
            return cout << k + i - 1 << endl, void();
        else sum += b[i];
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}