#include "Monday.h"

using namespace virmar;

const int N = 5E3 + 6;

int n, m, q;

ll p[N] = {1}, C[N] = {1};

void doit() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) p[i] = (p[i - 1] * 2) % q;
    for (int i = 1; i <= n; i++)
        for (int j = i; j >= 1; j--)
            C[j] = (C[j] + C[j - 1]) % q;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll t1 = qpow(2, (n - i) * (m - 1), q), t2 = qpow(p[i] - 1, m - 1, q);
        ans = (ans + C[i] * t1 % q * t2 % q) % q;
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}