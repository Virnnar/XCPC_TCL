#include "Monday.h"

using namespace virmar;

const int N = 100;

int n, m;
int a[N][N];

void doit() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    if (n * m == 1) return puts("-1"), void();
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            cout << a[i][j] % (n * m) + 1 << ' ';
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}