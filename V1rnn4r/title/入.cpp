#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;
using ll = long long;

#define mset(a, t) memset(a, t, sizeof a)

const int N = 42, M = N * (N - 1);

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * f;
}

struct {
    int next, to;
} e[M];
int head[N], num;
ll st[N];

inline void add(int from, int to) {
    e[num] = {head[from], to};
    head[from] = num++;
}

int n, m, ans = 0;

bool v[N];
ll state;
int p[N], cnt = 0;

inline bool jud() {
    if (cnt <= 2) return true;
    if ((state - (1ll << p[cnt - 1])) & (st[p[cnt]])) return false;
    return true;
}

void dfs(int now) {
    if (jud()) {
        ans = max(ans, cnt);
    } else return;

    for (int i = head[now]; ~i; i = e[i].next) {
        if (v[e[i].to]) continue;

        v[e[i].to] = true;
        p[++cnt] = e[i].to;
        state |= 1ll << e[i].to;

        dfs(e[i].to);

        cnt--;
        state -= 1ll << e[i].to;
        v[e[i].to] = false;
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) head[i] = -1;
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        add(u, v), add(v, u);
        st[u] |= 1ll << v;
        st[v] |= 1ll << u;
    }
    for (int i = 1; i <= n; i++) {
        p[++cnt] = i;
        v[i] = true;
        state |= 1ll << i;
        dfs(i);
        state -= 1ll << i;
        cnt--;
        v[i] = false;
    }
    cout << ans << endl;
}
