#include "Monday.h"

using namespace virmar;

const int N = 1E6 + 6;

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int n = 2, m;
string a[5];
bool v[5][N];

int f[3][N];


inline int jud(int x, int y) {return 1 <= x and x <= n and 1 <= y and y <= m;}

void doit() {
    cin >> m;
    cin >> a[1] >> a[2];
    a[1] = '_' + a[1];
    a[2] = '_' + a[2];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            v[i][j] = (a[i][j] == 'R');
    for (int i = 1; i <= m; i++) {
        if (v[1][i]) f[1][i] = max(f[1][i], f[1][i - 1] + 1);
        if (v[2][i]) f[2][i] = max(f[2][i], f[2][i - 1] + 1);

        if (v[1][i] == true and v[2][i] == true) {
            int p = f[1][i], q = f[2][i];

            f[1][i] = max(f[1][i], q + 1);
            f[2][i] = max(f[2][i], p + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, f[i][j] - 1);
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}