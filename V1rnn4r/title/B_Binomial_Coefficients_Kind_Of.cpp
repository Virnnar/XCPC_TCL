#include "Monday.h"

using namespace virmar;

const int N = 2E5 + 6, MOD = 1E9 + 7;

int a[N], b[N];

void doit() {
    
}

int main() {
    virmar::READ_ARC = false;
    // for (int i = 0; i < 100; i++) {
    //     C[i][0] = C[i][i] = 1;
    //     for (int j = 1; j < i; j++)
    //         C[i][j] = C[i][j - 1] + C[i - 1][j - 1];
    //     for (int j = 0; j <= i; j++)
    //         cout << C[i][j] << ' ';
    //     cout << endl;
    // }
    // return 0;
    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) cin >> a[i];
    for (int i = 1; i <= T; i++) cin >> b[i];
    for (int i = 1; i <= T; i++)
        if (a[i] == b[i]) puts("1");
        else cout << qpow(2, b[i], MOD) << endl;
    return 0;
}

