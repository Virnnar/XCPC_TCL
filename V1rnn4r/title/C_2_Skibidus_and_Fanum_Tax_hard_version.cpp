#include "Monday.h"

using namespace virmar;


void doit() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    if (n == 1) return puts("YES"), void();

    sort(b.begin(), b.end());

    a[0] = min(a[0], b[0] - a[0]);

    for (int i = 1; i < n; i++) {
        int val = a[i] * 2;
        auto idx = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]);
        if (idx != b.end()) val = *idx;
        a[i] = min(a[i], val - a[i]);
        if (a[i] < a[i - 1]) a[i] = val - a[i];
        if (a[i] < a[i - 1]) return puts("NO"), void();
    }



    puts("YES");
}
int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}