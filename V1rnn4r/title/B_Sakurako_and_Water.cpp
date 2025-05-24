#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    ll ans = 0;
    vector<ll> d(2 * n, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            ll t; cin >> t;
            if (t < 0)
                d[j - i + n] = max(d[j - i + n], -t);
        }
    for (int i = 1; i <= n + n - 1; i++)
        ans += d[i];
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

