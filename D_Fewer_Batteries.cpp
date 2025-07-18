#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n, m; cin >> n >> m;
    vector<int> b(n);
    for (auto &i : b) cin >> i;

    vector<vector<pair<int, int> > > g(n);

    for (int i = 0; i < m; i++) {
        int s, t, w; cin >> s >> t >> w;
        s--, t--;
        g[s].push_back({t, w});
    }

    auto check = [&](int x) {
        vector<int> f(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0 and f[i] == 0) continue;
            f[i] += b[i];
            f[i] = min(f[i], x);
            for (auto p : g[i]) {
                if (p.second <= f[i])
                    f[p.first] = max(f[p.first], f[i]);
            }
        }
        return (f.back() > 0);
    };

    if (!check(INF)) return puts("-1"), void();
    int l = 0, r = INF;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

void init() {

}