#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    int t = n / 2 + 1;
    ll ans = INF;
    for (int i = t; i <= n; i++)
        ans = min(ans, s[i] - s[i - t]);
    cout << ans << ' ' << s[n] - ans << endl;

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}