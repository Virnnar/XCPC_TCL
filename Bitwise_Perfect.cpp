#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    if (n > 60) return puts("YES"), void();

    vector<int> v(70, 0);
    for(auto x: a) {
        while (x - (x & -x) > 0) x -= x & -x;
        if (v[__builtin_ctz(x)]) return puts("NO"), void();
        v[__builtin_ctz(x)] = 1;
        
    }
    puts("YES");
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