#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    
    auto done = [&](int t, int a, int b, int x, int y) {
        int res = 0;
        res += max((t - a + x) / x, 0);
        t -= max((t - a + x) / x, 0) * x;
        res += max((t - b + y) / y, 0);
        return res;
    };

    cout << max(done(k, a, b, x, y), done(k, b, a, y, x)) << endl;
}

signed main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

void init() {

}