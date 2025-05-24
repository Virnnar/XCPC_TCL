#include "Monday.h"

using namespace virmar;

const int N = 4E2 + 6, M = 1E4 + 6;
const double EPS = 1E-9;

struct edge {
    int u, v;
    double c, t;
} e[M];

int n, m, f;
int s[N];

int find(int x, int f[] = s) {
    if (x == f[x]) return x;
    int root = find(f[x]);
    return f[x] = root;
}

bool check(double x) {
    double res = 0;
    sort(e + 1, e + m + 1, [=](edge u, edge v){
        double p = x * u.t + u.c, q = x * v.t + v.c;
        return p < q;
    });
    iota(s, s + n + 1, 0);
    
    for (int i = 1; i <= m; i++)
        if (find(e[i].u) != find(e[i].v)) {
            res += x * e[i].t + e[i].c;
            s[find(e[i].u)] = find(e[i].v);
        }

    return res > f;
}

void doit() {
    cin >> n >> m >> f;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].c >> e[i].t;
    if (check(0)) return cout << "0.0000" << endl, void();
    double l = 0, r = 1E14;
    while (r - l > EPS) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid - EPS;
        else l = mid + EPS;
    }
    
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; //cin >> T;
    while (T--) doit();
    return 0;
}