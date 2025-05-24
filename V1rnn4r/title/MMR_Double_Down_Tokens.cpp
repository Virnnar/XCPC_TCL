#include "Monday.h"

using namespace virmar;

const int MOD = 998244353;

bool jud(int x) {
    for (int i = 2; (ll) i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

ll n, m, k;

void doit() {
    cin >> n >> m >> k;
    ll frc = 1;
    for (int i = 1; i <= n + m; i++) frc *= i;
    for (int i = 1; i <= n; i++) frc /= i;
    for (int i = 1; i <= m; i++) frc /= i;


    ll t = min(n, k);
    ll ans = 0;
    for (int i = 1; i <= t; i++)
        ans += max((ll)i, n - m);
    ll d = gcd(ans, frc);
    ans /= d, frc /= d;
    cout << ans * qpow(frc, MOD - 2, MOD);
}

int main() {
    virmar::READ_ARC = false;
    int T = 1;// cin >> T;
    while (T--) doit();
    return 0;
}