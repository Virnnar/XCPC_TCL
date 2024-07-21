#include "Monday.h"

using namespace virmar;

const int N = 1E5 + 6, M = N << 2;

int n, m;
ll MOD;
ll a[N];

struct {
    int l, r;
    ll val;
} tr[M];
ll add[M], mul[M];

inline int ls(int now) {return now << 1;}
inline int rs(int now) {return now << 1 | 1;}

void push_up(int now) {
    tr[now].val = (tr[ls(now)].val + tr[rs(now)].val) % MOD;
}

void build(int now, int l, int r) {
    add[now] = 0, mul[now] = 1;
    tr[now].l = l, tr[now].r = r;
    if (l == r) {tr[now].val = a[l]; return;}
    int mid = (l + r) >> 1;
    build(ls(now), l, mid);
    build(rs(now), mid + 1, r);
    push_up(now);
}

void add_tag(int now, ll d) {
    add[now] = (add[now] + d) % MOD;
    tr[now].val = (tr[now].val + (d * (tr[now].r - tr[now].l + 1)) % MOD) % MOD;
    // add[now] += d;
    // tr[now].val += d * (tr[now].r - tr[now].l + 1);
}

void mul_tag(int now, ll d) {
    mul[now] = (mul[now] * d) % MOD;
    add[now] = (add[now] * d) % MOD;
    tr[now].val = (tr[now].val * d) % MOD;
}

void push_down(int now) {
    auto &fa = tr[now], &lson = tr[ls(now)], &rson = tr[rs(now)];

    lson.val = ((lson.val * mul[now]) % MOD + add[now] * (lson.r - lson.l + 1) % MOD) % MOD;
    add[ls(now)] = (add[ls(now)] * mul[now] + add[now]) % MOD;
    mul[ls(now)] = (mul[ls(now)] * mul[now]) % MOD;

    rson.val = ((rson.val * mul[now]) % MOD + add[now] * (rson.r - rson.l + 1) % MOD) % MOD;
    add[rs(now)] = (add[rs(now)] * mul[now] + add[now]) % MOD;
    mul[rs(now)] = (mul[rs(now)] * mul[now]) % MOD;

    add[now] = 0, mul[now] = 1;
}

void add_to(int now, int L, int R, ll d) {
    int l = tr[now].l, r = tr[now].r;
    if (L <= l and r <= R) { add_tag(now, d); return; }
    push_down(now);
    int mid = (l + r) >> 1;
    if (L <= mid) add_to(ls(now), L, R, d);
    if (R > mid)  add_to(rs(now), L, R, d);
    push_up(now);
}

void mul_to(int now, int L, int R, ll d) {
    int l = tr[now].l, r = tr[now].r;
    if (L <= l and r <= R) { mul_tag(now, d); return; }
    push_down(now);
    int mid = (l + r) >> 1;
    if (L <= mid) mul_to(ls(now), L, R, d);
    if (R > mid)  mul_to(rs(now), L, R, d);
    push_up(now);
}

ll query(int now, int L, int R) {
    int l = tr[now].l, r = tr[now].r;
    if (L <= l and r <= R) return tr[now].val;
    push_down(now);
    ll res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) res = (res + query(ls(now), L, R)) % MOD;
    if (R > mid)  res = (res + query(rs(now), L, R)) % MOD;
    // if (L <= mid) res += query(ls(now), L, R);
    // if (R > mid)  res += query(rs(now), L, R);
    push_up(now);
    return res;
}

void doit() {
    cin >> n >> m >> MOD;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt, x, y; cin >> opt >> x >> y;
        if (opt == 1) {
            ll k; cin >> k;
            mul_to(1, x, y, k);
        }
        if (opt == 2) {
            ll k; cin >> k;
            add_to(1, x, y, k);
        }
        if (opt == 3) {
            cout << query(1, x, y) % MOD << endl;
        }
    }
}

// 6 5 3 4

int main() {
    virmar::READ_ARC = false;
    int T = 1;// cin >> T;
    while (T--) doit();
    return 0;
}