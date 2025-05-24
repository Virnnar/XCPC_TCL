#include "Monday.h"

using namespace virmar;

const int N = 1E6 + 6;

ll ans = 0;
int n, m;
vector<int> a[N];
pair<int, int> itv[N];
ll f[N];

void doit() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        itv[i].first = itv[i].second = i;
        if (a[i].size() == 0) continue;
        sort(a[i].begin(), a[i].end(), [=](int u, int v) {
            if (u < i and v < i) return u > v;
            return u < v;
        });
        
        for (auto t: a[i])
            if (t == itv[i].first - 1) itv[i].first--;
            else if (t == itv[i].second + 1) itv[i].second++;
    }
    for (int i = 1; i <= n; i++) f[i] = itv[i].second - itv[i].first + 1;
    for (int i = n - 1; i >= 1; i--)
        f[i] = min(f[i], f[i + 1] + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += f[i];
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}

/*
1: 2 3 4 5
2: 1 3 4 5
3: 5
4: 5

*/