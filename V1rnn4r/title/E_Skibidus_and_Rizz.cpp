#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k < abs(n - m) or k > max(n, m)) return puts("-1"), void();

    string a = "0", b = "1";
    if (n < m) swap(n, m), swap(a, b);
    string ans(k, a[0]);
    n -= k;
    while (m > n) {
        ans += b;
        m--;
    }
    while (n--)
        ans += ans.back() == b[0] ? a + b : b + a;
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}