#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1), suf(n + 1);
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (++pre[a[i]] == 1) cnt++;
    }

    for (int i = n; i; i--) {
        int x = a[i];
        pre[x]--, suf[x]++;
        if (pre[x] == 0) cnt--;
        if (suf[x] == 2) {
            ans += cnt;
            if (pre[x] > 0) ans--;
        }
    }

    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}