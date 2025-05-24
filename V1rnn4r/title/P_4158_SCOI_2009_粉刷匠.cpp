#include "Monday.h"

using namespace virmar;

const int N = 100, M = 2E5 + 6;

int n, m, k;
int ans[M], f[N][N][5];

void doit() {
    cin >> n >> m >> k;
    for (int now = 1; now <= n; now++) {
        string s; cin >> s; s = '_' + s;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= i; j++) {
                int c = s[i] - '0';
                f[i][j][c] = f[i - 1][j][c] + 1;
                f[i][j][c ^ 1] = f[i - 1][j][c ^ 1];
                int max_val = max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]);
                f[i][j][c] = max(f[i][j][c], max_val + 1);
                f[i][j][c ^ 1] = max(f[i][j][c ^ 1], max_val);
            }
        for (int i = k; i >= 1; i--)
            for (int j = 0; j <= min(m, i); j++)
                ans[i] = max(ans[i], ans[i - j] + max(f[m][j][0], f[m][j][1]));
    }
    cout << ans[k] << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}