#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    set<int> up, lw;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (y == 1) up.insert(x);
        else lw.insert(x);
        // cout << x << ' ' << y << endl;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (up.count(i) and lw.count(i)) ans += n - 2;
        if (up.count(i) and lw.count(i - 1) and lw.count(i + 1)) ans++;
        if (lw.count(i) and up.count(i - 1) and up.count(i + 1)) ans++;
        // cout << up.count(i) << ' ';
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}