#include "Monday.h"

using namespace virmar;

ll n, k;

ll sum(ll st, ll ed) {
    return (st + ed) * (ed - st + 1) / 2;
}

ll get(ll x) {
    ll p = sum(k, x), q = sum(x + 1, k + n - 1);
    return abs(p - q);
}

void doit() {
    cin >> n >> k;
    ll l = k, r = k + n - 1;
    while (l < r) {
        ll k = (r - l) / 3;
        ll lmid = l + k, rmid = r - k;
        if (get(lmid) <= get(rmid)) r = rmid - 1;
        else l = lmid + 1;
    }
    cout << min(get(l), get(r)) << endl;
}


int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}