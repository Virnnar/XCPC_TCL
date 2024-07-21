#include "Monday.h"

using namespace virmar;

const int N = 2E2 + 6;
const int MOD = 1E9 + 7;

int n, m, k;
string a, b;
int f[N][N], s[N][N];

void doit() {
    cin >> n >> m >> k;
    cin >> a >> b;
    a = '_' + a;
    b = '_' + b;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            for (int t = k; t >= 1; t--)
                f[j][t] = (f[j][t] + (s[j][t] = a[i] == b[j] ? s[j - 1][t] + f[j - 1][t - 1] : 0)) % MOD;
    cout << f[m][k] << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}