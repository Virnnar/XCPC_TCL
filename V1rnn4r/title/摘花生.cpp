#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m; cin >> n >> m;
    matrix(a, n + 1, m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    matrix(f, n + 1, m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
    cout << f[n][m] << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit(); 
    return 0;
}