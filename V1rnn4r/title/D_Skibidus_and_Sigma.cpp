#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m; cin >> n >> m;
    vector<vector<ll> > a(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        a[i].push_back(0);
        for (int j = 0; j < m; j++)
            a[i].back() += a[i][j];
    }

    sort(a.begin(), a.end(), [&](vector<ll> a, vector<ll> b) {
        return a.back() > b.back();
    });

    ll ans = 0, cnt = n * m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += cnt-- * a[i][j];

    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}