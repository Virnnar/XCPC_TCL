#include "Monday.h"

using namespace virmar;

void init();

bool v[10000010];
int pri[10000000], cnt;

void primes() {
    for (int i = 2; i <= 1E7; i++) {
        if (!v[i]) pri[++cnt] = i;
        for (int j = 1; j <= cnt and i * pri[j] <= 1E7; j++) {
            v[i * pri[j]] = true;
            if (i % pri[j] == 0) break;
        }
    }
}

void doit() {
    ll n, ans = 0; cin >> n;
    for (int i = 1; i <= cnt; i++)
        if (pri[i] <= n)
            ans += n / pri[i];
        else break;
    cout << ans << endl;
}
int main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

void init() {
    primes();
}