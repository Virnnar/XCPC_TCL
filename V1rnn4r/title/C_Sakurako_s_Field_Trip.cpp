#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n / 2; i++)
        if (a[i] == a[i - 1] or a[n - i + 1] == a[n - i + 2])
            swap(a[i], a[n - i + 1]);
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += a[i] == a[i + 1];
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}