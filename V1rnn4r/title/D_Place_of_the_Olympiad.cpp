#include "Monday.h"

using namespace virmar;

void doit() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 0, r = m;

    while (l < r) {
        ll mid = l + r >> 1;
        if ((m / (mid + 1) * mid + m % (mid + 1)) * n >= k)
            r = mid;
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