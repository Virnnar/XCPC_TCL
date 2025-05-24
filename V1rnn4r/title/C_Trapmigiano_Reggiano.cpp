#include "Monday.h"

using namespace virmar;

void doit() {
    int n, st, ed;
    cin >> n >> st >> ed;
    vector<vector<int> > adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    vector<vector<int> > dep(n + 1, vector<int>());
    vector<int> d(n + 1);

    auto dfs = [&](auto &&self, int now, int fa) -> void {
        d[now] = d[fa] + 1;
        dep[d[now]].push_back(now);
        for (int to: adj[now]) {
            if (to == fa) continue;
            self(self, to, now);
        }
    };

    dfs(dfs, ed, 0);
    
    for (int i = n; i >= 1; i--) {
        for (auto v: dep[i])
            cout << v << ' ';
    }
    puts("");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}