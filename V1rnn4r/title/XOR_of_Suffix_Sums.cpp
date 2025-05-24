#include "Monday.h"

using namespace virmar;

const int N = 5E5 + 6, M = N << 2;
const int MOD = 2097152;

struct {
    int l, r;
    ll val;
} tr[M];
ll add[M];

inline int ls(int now) {return now << 1;}
inline int rs(int now) {return now << 1 | 1;}

void push_up(int now) {
    tr[now].val = (tr[ls(now)].val + tr[rs(now)].val);
}

void build(int now, int l, int r) {
    add[now] = 0;
    tr[now].l = l, tr[now].r = r;
    if (l == r) {tr[now].val = 0; return;}
    int mid = (l + r) >> 1;
    build(ls(now), l, mid);
    build(rs(now), mid + 1, r);
    push_up(now);
}

void add_tag(int now, ll d) {
    add[now] = (add[now] + d);
    tr[now].val = (tr[now].val + (d * (tr[now].r - tr[now].l + 1)));
}

void push_down(int now) {
    // auto &fa = tr[now], &lson = tr[ls(now)], &rson = tr[rs(now)];

    // lson.val = (lson.val % MOD + add[now] * (lson.r - lson.l + 1) % MOD) % MOD;
    // add[ls(now)] = (add[ls(now)] + add[now]) % MOD;

    // rson.val = (rson.val % MOD + add[now] * (rson.r - rson.l + 1) % MOD) % MOD;
    // add[rs(now)] = (add[rs(now)] + add[now]) % MOD;

    // add[now] = 0;

    auto &fa = tr[now], &lson = tr[ls(now)], &rson = tr[rs(now)];

    lson.val = (lson.val + add[now] * (lson.r - lson.l + 1));
    add[ls(now)] = (add[ls(now)] + add[now]);

    rson.val = (rson.val + add[now] * (rson.r - rson.l + 1));
    add[rs(now)] = (add[rs(now)] + add[now]);

    add[now] = 0;
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

ll query(int now, int L, int R) {
    int l = tr[now].l, r = tr[now].r;
    if (L <= l and r <= R) return tr[now].val;
    push_down(now);
    ll res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) res = (res + query(ls(now), L, R));
    if (R > mid)  res = (res + query(rs(now), L, R));
    push_up(now);
    return res;
}

ll query_xor(int now, int L, int R) {
    int l = tr[now].l, r = tr[now].r;
    if (l == r) return tr[now].val;
    push_down(now);
    ll res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) res ^= query_xor(ls(now), L, R);
    if (R > mid)  res ^= query_xor(rs(now), L, R);
    push_up(now);
    return res;
}

int n, idx = 0;
ll t[N], v[N];

void doit() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> v[i];
    build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        if (t[i]) {
            for (int j = 1; j <= t[i]; j++) {
                ll del = v[i - j];
                add_to(1, 1, idx, -del);
                idx--;
            }
        }
        ++idx;
        add_to(1, 1, idx, v[i]);
        for (int j = 1; j <= idx; j++)
            cout << query(1, j, j) << ' ';
        cout << endl;
        // cout << query_xor(1, 1, idx) % MOD << endl;
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1;// cin >> T;
    while (T--) doit();
    return 0;
}
