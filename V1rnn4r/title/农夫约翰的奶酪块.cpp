#include "Monday.h"

using namespace virmar;

void doit() {
    int n, q, ans = 0; cin >> n >> q;
    vector<vector<int> > a(n + 1, vector<int>(n + 1)), b(n + 1, vector<int>(n + 1)), c(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= q; i++) {
        int x, y, z; cin >> x >> y >> z;
        if (++a[x][y] == n) ans++;
        if (++b[x][z] == n) ans++;
        if (++c[y][z] == n) ans++;
        cout << ans << '\n';
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}