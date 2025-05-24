#include "Monday.h"

using namespace virmar;

void doit() {
    bool ans = true;
    int n; cin >> n;
    vector<int> a(n + 2, 0);
    int t; cin >> t; a[t] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> t;
        if (!(a[t + 1] or a[t - 1])) ans = false;
        a[t] = 1;
    }
    puts(ans ? "YES" : "NO");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}