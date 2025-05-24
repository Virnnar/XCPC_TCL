#include "Monday.h"

using namespace virmar;

void doit() {
    int n, k, s = 0, ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    for (auto i: a)
        if (i >= k) s += i;
        else if (i == 0 and s) s--, ans++;
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}