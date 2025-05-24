#include "Monday.h"

using namespace virmar;

const int N = 5E3 + 6, M = 2E5 + 6;

struct {int next, to, dis;} e[M << 1];
int head[N], num;

void add(int from, int to, int dis) {
    e[num] = {head[from], to, dis};
    head[from] = num++;
}

int n, m;

struct node{
    int id, dis;
    node(int id, int dis) {this -> id = id; this -> dis = dis;}
    bool operator<(const node &t)const {
        return dis > t.dis;
    }
};

bool done[N];

void prim() {
    ll ans = 0, cnt = 0;
    mset(done, false);
    priority_queue<node> Q;
    Q.push(node(1, 0));
    while (Q.size()) {
        int now = Q.top().id, w = Q.top().dis; Q.pop();
        if (done[now]) continue;
        done[now] = true;
        ans += w;
        cnt++;
        for (int i = head[now]; ~i; i = e[i].next) {
            if (done[e[i].to]) continue;
            Q.push(node(e[i].to, e[i].dis));
        }
    }
    if (cnt == n) cout << ans << endl;
    else puts("orz");
}

void doit() {
    mset(head, -1);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    prim();
}

int main() {
    virmar::READ_ARC = false;
    int T = 1;// cin >> T;
    while (T--) doit();
    return 0;
}