#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a), greater<int>());

    int res = 0;

    for (int i = 0, cnt = 1; i < n; i++, cnt++) {
        if (a[i] * cnt >= m) {
            ans++;
            cnt = 0;
        }
    }

    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}