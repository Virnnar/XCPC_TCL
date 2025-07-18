#include "Monday.h"

using namespace virmar;

void init();

const int MOD = 998244353;

void doit() {
    int n; cin >> n;
    vector<int> a;
    a.emplace_back(2);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (t != a.back()) a.emplace_back(t), ans += t == 1;
    }
    int cnt1 = 0, cnt0 = 0; // 1 for minus ; 0 for add
    a[0] = 0, a.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1 and a[i + 1] == 1 and a[i - 1] == 1) cnt1++;
        if (a[i] == -1 and a[i + 1] == 0 and a[i - 1] == 0) cnt0++;
    }

    ans = qpow(2, cnt1 + cnt0, MOD) * ans % MOD;
    if (cnt0) ans = (ans + qpow(2, cnt0 - 1, MOD) * cnt0 % MOD) % MOD;
    if (cnt1) ans = (ans - qpow(2, cnt1 - 1, MOD) * cnt1 % MOD) % MOD;

    cout << ans << endl;
}

signed main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T --> 0) doit();
    return 0;
}

void init() {

}