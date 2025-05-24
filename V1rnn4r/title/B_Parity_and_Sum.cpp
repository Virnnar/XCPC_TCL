#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());

    int pos = -1, ans = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] & 1) pos = i;
        else ans++;
    if (pos == -1) return puts("0"), void();
    
    ll s = a[pos];
    for (int i = 0; i < a.size(); i++) {
        if (a[i] & 1) continue;
        if (a[i] > s) return cout << ans + 1 << endl, void();
        s = s + a[i];
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}



