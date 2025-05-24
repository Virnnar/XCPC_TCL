#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(m);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    while (q--) {
        int t; cin >> t;
        int p = lower_bound(a.begin(), a.end(), t) - a.begin(); // first greater
        if (p == 0) cout << a[0] - 1 << endl;
        else if (p == m) cout << n - a.back() << endl;
        else cout << (a[p] - a[p - 1]) / 2 << endl;
    }
    // puts("\n-----------");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}