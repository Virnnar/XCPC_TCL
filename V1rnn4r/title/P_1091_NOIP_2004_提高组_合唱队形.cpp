#include "Monday.h"

using namespace virmar;

int n;

void doit() {
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<int> f(n, 1), g(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
    for (int i = n - 1; i > 0; i--)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[i]) g[i] = max(g[i], g[j] + 1);
    int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     cout << f[i] << ' ';
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << g[i] << ' ';
    for (int i = 0; i < n; i++) ans = max(ans, f[i] + g[i] - 1);
    cout << n - ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}