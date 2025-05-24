#include "Monday.h"

using namespace std;

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> i;
    vector<vector<int> > f(n, vector<int>(n, INF));

    for (int i = 1; i < n; i++)
        f[i][i] = 0;

    for (int len = 2; len <= n - 1; len++)
        for (int i = 1; i + len - 1 <= n - 1; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[i - 1] * a[k] * a[j]);
        }
    cout << f[1][n - 1] << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1;// cin >> T;
    while (T--) doit();
    return 0;
}