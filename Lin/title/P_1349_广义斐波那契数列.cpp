#include "Monday.h"

using namespace virmar;

int p, q, a1, a2, n, m;

void doit() {
    cin >> p >> q >> a1 >> a2 >> n >> m;
    matrix t(2, 2, 10000);
    t[1][1] = p, t[1][2] = 1, t[2][1] = q, t[2][2] = 0;
    // for (int i = 1; i <= 2; i++, puts(""))
    //     for (int j = 1; j <= 2; j++)
    //         cout << t[i][j] << ' ';
    matrix res = t;
    for (int i = 1; i < n; i++) {
        for (int i = 1; i <= 2; i++, puts(""))
            for (int j = 1; j <= 2; j++)
                cout << res[i][j] << ' ';
        puts("-----");
        res = res * t;
    }
    for (int i = 1; i <= 2; i++, puts(""))
        for (int j = 1; j <= 2; j++)
            cout << t[i][j] << ' ';
}
// 1 1 2 3 5 8 13 21 34 55

int main() {
    virmar::READ_ARC = false;
    int T = 1; //  cin >> T;
    while (T--) doit();
    return 0;
}