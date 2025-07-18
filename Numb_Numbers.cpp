#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n, q; cin >> n >> q;
    vector<ll> ori(n);
    for (auto &x : ori) cin >> x;

    vector<ll> v = ori, now = ori;

    vector<pair<int, int> > updates(q);
    for (auto &[idx, val] : updates) {
        cin >> idx >> val;
        idx--;
        now[idx] += val;
        v.emplace_back(now[idx]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int k = v.size();

    vector<int> bi_tree(k + 1, 0);

    auto getidx = [&](ll val) -> int { // 离散化映射
        return lower_bound(all(v), val) - v.begin();
    };


    auto add = [&](int p, int v) -> void {
        p++;
        while (p <= k) {
            bi_tree[p] += v;
            p += p & -p;
        }
    };

    auto count = [&](int v) -> int {
        int res = 0, idx = 0;
        for (int i = 20; i >= 0; i--)
            if ((idx | (1 << i)) <= k && res + bi_tree[idx | (1 << i)] <= v) {
                idx |= 1 << i;
                res += bi_tree[idx];
            }
        return res;
    };

    for (auto &x: ori)
        add(getidx(x), 1);
    for (auto &[idx, val]: updates) {
        add(getidx(ori[idx]), -1); // 删除原先数
        ori[idx] += val;
        add(getidx(ori[idx]), 1);
        cout << count(n - n / 2) << endl;
    }
}

signed main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T --> 0) doit();
    return 0;
}

void init() {

}