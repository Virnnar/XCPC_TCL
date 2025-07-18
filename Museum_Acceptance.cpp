#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<vector<int> > e(n);
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int v; cin >> v;
            e[i].emplace_back(v - 1);
        }
    }

    auto nxt = [&](pair<int, int> cur) -> pair<int, int> {
        auto [u, uid] = cur;
        int v = e[u][uid];
        int vid = 0;
        while (e[v][vid] != u) vid++;
        return {v, vid};
    }; // 得到双向边的另一个点的表示

    auto get = [&](pair<int, int> cur) -> pair<int, int> {
        return min(nxt(cur), cur);
    }; // 双向边选一条边做代表，一会放 set 计数用

    vector<vector<int> > v(n, vector<int>(3)), ans(n, vector<int>(3));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < e[i].size(); j++) {
            if (v[i][j]) continue;

            pair<int, int> cur = {i, j}, st = {i, j};
            set<pair<int, int> > s; // 记录环上的节点数量

            do {
                auto [u, uid] = cur;
                v[u][uid] = 1;
                s.insert(get(cur));
                cur = nxt(cur);
                cur.second = (cur.second + 1) % e[cur.first].size(); // 编号++
            } while (cur != st);

            cur = st;
            if (j) continue;
            do {
                auto [u, uid] = cur;
                ans[u][uid] = s.size(); // 环上的边都标记答案
                cur = nxt(cur);
                cur.second = (cur.second + 1) % e[cur.first].size();
            } while (cur != st);
        }
    for (int i = 0; i < n; i++)
        cout << ans[i][0] << endl;
}

signed main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; // cin >> T;
    while (T --> 0) doit();
    return 0;
}

void init() {

}