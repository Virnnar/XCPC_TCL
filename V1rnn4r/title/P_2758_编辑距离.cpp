#include "Monday.h"

using namespace virmar;

const int N = 2E3 + 6;

string a, b;
int n, m;
int f[N][N];

void doit() {
    cin >> a >> b;
    a = '_' + a;
    b = '_' + b;
    n = a.size(), m = b.size();
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int i = 1; i <= m; i++) f[0][i] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1];
            else f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
        }
    cout << f[n][m] << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1;// cin >> T;
    while (T--) doit();
    return 0;
}