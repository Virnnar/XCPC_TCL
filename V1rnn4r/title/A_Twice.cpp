#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a[t]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans+= a[i] / 2;
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}