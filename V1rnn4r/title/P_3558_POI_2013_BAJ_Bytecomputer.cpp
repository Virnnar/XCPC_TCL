#include "Monday.h"

using namespace virmar;

const int N = 1E6 + 6;

int n;
int a[N];
int f[N][5];

void doit() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // for (int i = 0; i <= 2; i++) f[1][i] = INF;
    mset(f, INF);
    f[1][a[1] + 1] = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == -1) {
            f[i][0] = f[i - 1][0];
            f[i][2] = f[i - 1][2] + 2;
        }
        if (a[i] == 0) {
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = min(f[i - 1][0], f[i - 1][1]);
            f[i][2] = f[i - 1][2] + 1;
        }
        if (a[i] == 1) {
            f[i][0] = f[i - 1][0] + 2;
            f[i][1] = f[i - 1][0] + 1;
            f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2]));
        }
    }
    int ans = min(f[n][0], min(f[n][1], f[n][2]));
    if (ans == INF) puts("BRAK");
    else cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}