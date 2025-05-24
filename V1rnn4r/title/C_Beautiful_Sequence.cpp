#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    int MOD = 998244353;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    vector<int> f(4, 0);
    f[0] = 1;
    for (auto x: a) {
        if (x == 2) f[x] = (f[x] + f[x]) % MOD;
        f[x] = (f[x] + f[x - 1]) % MOD;
    }
    cout << f[3] << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}