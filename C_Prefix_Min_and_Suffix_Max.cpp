#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<int> a(n + 1), min_val(n + 1), max_val(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    min_val[1] = a[1], max_val[n] = a[n];
    for (int i = 2; i <= n; i++) min_val[i] = min(min_val[i - 1], a[i]);
    for (int i = n - 1; i >= 1; i--) max_val[i] = max(max_val[i + 1], a[i]);
    // for (int i = 1; i <= n; i++) cout << min_val[i] << ' ';
    // puts("");
    // for (int i = 1; i <= n; i++) cout << max_val[i] << ' ';
    string ans = "1";
    for (int i = 2; i < n; i++)
        if (a[i] == max_val[i] or a[i] == min_val[i])
            ans += "1";
        else
            ans += "0";
    ans += "1";
    cout << ans << '\n';

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