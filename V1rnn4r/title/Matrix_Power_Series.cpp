#include "Monday.h"

using namespace virmar;

matrix base;

int n, m, k;

void display(matrix t) {
    for (int i = 1; i <= t.n; i++, puts(""))
        for (int j = 1; j <= t.m; j++)
            cout << t[i][j] << ' ';
    puts("---");
}

matrix qpow(matrix a, int b) {
    matrix res(2 * n);
    res.mod = a.mod;

    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void doit() {
    cin >> n >> k >> m;
    base.n = 2 * n;
    base.m = 2 * n;
    base.mod = m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> base[i][j];
            base[i + n][j] = base[i][j];
            if (i == j) base[i + n][j + n] = 1;
        }

    matrix s = qpow(base, k);
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= n; j++)
            cout << s[i + n][j] << ' ';
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}