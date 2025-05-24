#include "Monday.h"

using namespace virmar;

void doit() {
    int n, k; cin >> n >> k;
    map<int, int> H;
    for (int i = 1; i <= k; i++) {
        int u, v; cin >> u >> v;
        H[u] += v;
    }
    vector<pair<int, int> > a;
    for (auto i: H) a.push_back(i);

    sort(a.begin(), a.end(), [](pair<int, int> p, pair<int, int> q) {
        return p.second > q.second;
    });
    int ans = 0;
    for (int i = 0; i < min(n, (int)a.size()); i++)
        ans += a[i].second;
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}