#include "Monday.h"

using namespace virmar;

const int N = 1E5 + 6, M = N << 2;

struct {
    ll val;
    int lb, ub;
}tr[M];
ll add[M];

int n, m;
ll a[N];

inline int ls(int now) {return now << 1;}
inline int rs(int now) {return now << 1 | 1;}

inline void push_up(int now) {
    tr[now].val = tr[ls(now)].val + tr[rs(now)].val;
}

inline void add_tag(int now, ll d) {
    tr[now].val += d * (tr[now].ub - tr[now].lb + 1);
    add[now] += d;
}

inline void push_down(int now) {
    if (add[now]) {
        add_tag(ls(now), add[now]);
        add_tag(rs(now), add[now]);
        add[now] = 0;
    }
}

void build(int now, int l, int r) {
    add[now] = 0;
    tr[now].lb = l, tr[now].ub = r;
    if (l == r) {tr[now].val = a[l]; return;}
    int mid = (l + r) >> 1;
    build(ls(now), l, mid);
    build(rs(now), mid + 1, r);
    push_up(now);
}

void add_to(int now, int L, int R, ll d) {
    int l = tr[now].lb, r = tr[now].ub;
    if (L <= l and r <= R) {
        add_tag(now, d);
        return;
    }
    push_down(now);
    int mid = (l + r) >> 1;
    if (L <= mid) add_to(ls(now), L, R, d);
    if (R > mid)  add_to(rs(now), L, R, d);
    push_up(now);
}

ll query(int now, int L, int R) {
    int l = tr[now].lb, r = tr[now].ub;
    if (L <= l and r <= R) return tr[now].val;
    push_down(now);
    ll res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) res += query(ls(now), L, R);
    if (R > mid)  res += query(rs(now), L, R);
    push_up(now);
    return res;
}

void doit() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt, x, y; cin >> opt >> x >> y;
        if (opt == 1) {
            ll k; cin >> k;
            add_to(1, x, y, k);
        }
        if (opt == 2) {
            cout << query(1, x, y) << endl;
        }
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}