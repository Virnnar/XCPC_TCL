#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m; cin >> n >> m;
    vector<ll> w(2 * n + 1), s(2 * n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i], w[i] %= m;

    sort(w.begin() + 1, w.begin() + n + 1);
    for (int i = 1; i <= n; i++) w[i + n] = w[i] + m;
    for (int i = 1; i <= 2 * n; i++) s[i] = s[i - 1] + w[i];
    
    ll ans = INF;
    for (int l = 1; l <= n; l++) {
        int r = l + n - 1, p = (l + r) >> 1;
        ll L = (p - l + 1) * w[p] - (s[p] - s[l - 1]);
        ll R = (s[r] - s[p]) - (r - p) * w[p];
        ans = min(ans, L + R);
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}