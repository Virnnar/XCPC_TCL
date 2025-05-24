#include "Monday.h"

using namespace virmar;

ll m, k, h;

bool check(ll x) {
    ll res = x, tot = x;
    while (true) {
        res += (tot / m) * k;
        tot = (tot / m) * k + tot % m;
        if (res >= h) return true;
        if (tot < m) break;
    }
    return false;
}

bool jud(ll x) {
    ll t = x + k * ((x - k) / (m - k));
    return t >= h;
}

void doit() {
    cin >> m >> k >> h;
    if (m == k) return cout << min(m, h) << endl, void();
    ll l = 1, r = 1E9 + 1;
    // for (int i = 1; i <= 10; i++)
    //     cout << check(i) << ' ';
    // cout << endl;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (jud(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}