#include "Monday.h"

using namespace virmar;

const int N = 4E4 + 6;

int n;
int a[N], f[N];
int s[N], len;
ll g[N];
vector<int> pre[N];
ll s1[N], s2[N];

void first() {
    for (int i = 1; i <= n; i++) {
        if (s[len] <= a[i]) {
            s[++len] = a[i];
            pre[len].push_back(i);
            f[i] = len;
        } else {
            int p = upper_bound(s, s + len + 1, a[i]) - s;
            s[p] = a[i];
            pre[p].push_back(i);
            f[i] = p;
        }
    }
    cout << n - len << endl;

    pre[0].push_back(0);
    a[0] = -200000;
    a[n + 1] = 200000;
    f[n + 1] = len + 1;
    g[n + 1] = 10000000000;

    for (int j = 1; j <= n + 1; j++)
        for (int p = 0; p < pre[f[j] - 1].size(); p++) {
            int i = pre[f[j] - 1][p];
            if (i > j or a[i] > a[j]) continue;

            s1[i] = s2[j] = 0;
            for (int t = i + 1; t < j; t++) s1[t] = s1[t - 1] + abs(a[t] - a[i]);
            for (int t = j - 1; t > i; t--) s2[t] = s2[t + 1] + abs(a[t] - a[j]);

            ll ans = 10000000000;

            for (int k = i; k < j; k++)
                ans = min(ans, s1[k] + s2[k + 1]);
            g[j] = min(g[j], g[i] + ans);
        }
    cout << g[n + 1] << endl;
}

void doit() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] -= i, g[i] = 10000000000;
    first();

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}
