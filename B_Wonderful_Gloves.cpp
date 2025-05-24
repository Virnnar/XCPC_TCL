#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++)
        if (a[i] < b[i]) swap(a[i], b[i]);

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += a[i];
    sort(all(b), greater<>());
    for (int i = 0; i < k - 1; i++) ans += b[i];

    cout << ans + 1 << endl;
}

int main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

void init() {

}