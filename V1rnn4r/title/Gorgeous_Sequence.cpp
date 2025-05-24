#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>

#define mset(a, t) memset(a, t, sizeof a)

using namespace std;
using ll = long long;

inline ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * f;
}

const int N = 1E6 + 3, M = N << 2;

struct {
    int l, r;
    ll val;
    int max_val, max_cnt;
    int mex_val;
    int mini;
} tr[M];

inline int ls(int now) {return now << 1;}
inline int rs(int now) {return now << 1 | 1;}

int n, m;
int a[N];

inline void push_up(int now) {
    tr[now].val = tr[ls(now)].val + tr[rs(now)].val;
    tr[now].max_val = max(tr[ls(now)].max_val, tr[rs(now)].max_val);
    tr[now].max_cnt = tr[ls(now)].max_cnt * (tr[ls(now)].max_val == tr[now].max_val) + tr[rs(now)].max_cnt * (tr[rs(now)].max_val == tr[now].max_val);
    tr[now].mex_val = max(min(tr[ls(now)].max_val, tr[rs(now)].max_val), max(tr[ls(now)].mex_val, tr[rs(now)].mex_val));
}

inline void build(int now, int l, int r) {
    tr[now].l = l, tr[now].r = r;
    tr[now].mini = -1;
    if (l == r) {
        tr[now].val = tr[now].max_val = a[l];
        tr[now].max_cnt = 1;
        // tr[now].mex_val = -1;
        return;
    }

    int mid = (l + r) >> 1;
    build(ls(now), l, mid);
    build(rs(now), mid + 1, r);
    push_up(now);
}

inline void min_tag(int now, ll x) {
    if (tr[now].mex_val < x and x < tr[now].max_val) {
        tr[now].val += tr[now].max_cnt * (x - tr[now].max_val);
        tr[now].max_val = x;
        tr[now].mini = x;
    }
}

inline void push_down(int now) {
    if (~tr[now].mini) {
        min_tag(ls(now), tr[now].mini);
        min_tag(rs(now), tr[now].mini);
        tr[now].mini = -1;
    }
}

ll query(int now, int L, int R) {
    int l = tr[now].l, r = tr[now].r;
    if (L <= l and r <= R) {return tr[now].val;}
    push_down(now);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (L <= mid) res += query(ls(now), L, R);
    if (R > mid)  res += query(rs(now), L, R);
    push_up(now);
    return res;
}

ll query_max(int now, int L, int R) {
    int l = tr[now].l, r = tr[now].r;
    if (L <= l and r <= R) {return tr[now].max_val;}
    push_down(now);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (L <= mid) res = max(res, query_max(ls(now), L, R));
    if (R > mid)  res = max(res, query_max(rs(now), L, R));
    push_up(now);
    return res;
}

void min_to(int now, int L, int R, ll x) {
    if (tr[now].max_val <= x) return;
    int l = tr[now].l, r = tr[now].r;
    if (L <= l and r <= R and x > tr[now].mex_val) {
        min_tag(now, x);
        return;
    }
    push_down(now);
    int mid = (l + r) >> 1;
    if (L <= mid) min_to(ls(now), L, R, x);
    if (R > mid)  min_to(rs(now), L, R, x);
    push_up(now);
}

void doit() {
    // mset(tr, 0);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt, l, r;
        scanf("%d %d %d", &opt, &l, &r);
        if (opt == 0) {
            ll k;
            scanf("%lld", &k);
            min_to(1, l, r, k);
        }
        if (opt == 1)
            printf("%lld\n", query_max(1, l, r));
        if (opt == 2)
            printf("%lld\n", query(1, l, r));
    }
}

int main() {
    // virmar::READ_ARC = true;
    int T = 1; cin >> T;
    while (T --> 0) doit();
    return 0;
}