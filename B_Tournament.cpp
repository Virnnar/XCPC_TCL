#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n, j, k; cin >> n >> j >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (k == 1 and *max_element(all(a)) != a[j]) return puts("NO"), void();
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