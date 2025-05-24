#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    if (n == 1) return puts("YES"), void();

    a[0] = min(a[0], b[0] - a[0]);

    for (int i = 1; i < n; i++) {
        a[i] = min(a[i], b[0] - a[i]);
        if (a[i] < a[i - 1]) a[i] = b[0] - a[i];
        if (a[i] < a[i - 1]) return puts("NO"), void();
    }
    puts("YES");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}