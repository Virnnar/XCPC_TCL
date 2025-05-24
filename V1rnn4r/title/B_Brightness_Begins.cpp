#include "Monday.h"

using namespace virmar;

ll check(ll x) {
    return x - (ll)sqrtl(x);
}

void doit() {
    ll k; cin >> k;
    ll l = 1, r = 2E18;
    while (l < r) {
        ll mid = l + r >> 1ll;
        if (check(mid) >= k) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    // for (int i = 1; i <= 10; i++)
    //     cout << check(i) << ' ';
    // return 0;
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}