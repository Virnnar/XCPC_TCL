#include "Monday.h"

using namespace virmar;

const int N = 2E5 + 6, MOD = 1E9 + 7;

ll fact[N];

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

ll C(ll n, ll k) {
    if (n < k) return 0;
    return (fact[n] * qpow((fact[n - k] * fact[k]) % MOD, MOD - 2, MOD)) % MOD;
}

void doit() {
    int n, k, ones = 0; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        ones += t;
    }
    ll ans = 0;
    for ( int now = k / 2 + 1; now <= min(ones, k); now++) {
        ans += C(ones, now) * C(n - ones, k - now) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    init();
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}