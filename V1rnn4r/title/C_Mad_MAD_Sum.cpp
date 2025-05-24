#include "Monday.h"

using namespace virmar;

void handle(vector<int> &a) {
    vector<int> cnt(a.size() + 1, 0);
    int mad_val = 0;
    for (auto &i: a) {
        if (cnt[i]) mad_val = max(mad_val, i);
        cnt[i]++;
        i = mad_val;
    }
}

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    ll ans = 0;
    for (auto &i: a) ans += i;
    handle(a);
    for (auto &i: a) ans += i;
    handle(a);
    for (int i = 0; i < n; i++) ans += (ll)(n - i) * a[i];
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}