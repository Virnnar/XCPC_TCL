#include "Monday.h"

using namespace virmar;

const int N = 1E5 + 6;

int n;
int a[N];

void doit() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int pref_max_val = 0, max_val = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        pref_max_val = max(pref_max_val, a[i]);

        ans += pref_max_val - a[i];
        max_val = max(max_val, pref_max_val - a[i]);
    }
    cout << ans + max_val << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}