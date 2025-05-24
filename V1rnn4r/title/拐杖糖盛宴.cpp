#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m; cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 1; i <= m; i++) {
        int t = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] < t) continue;
            int temp = min(a[j], (ll)b[i]) - t;
            a[j] += temp;
            t += temp;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}