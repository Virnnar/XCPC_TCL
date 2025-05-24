#include<iostream>
#include<cstdio>

using namespace std;

const int N = 5E4 + 6;

int n, m, ans = 0;
int f[N], d[N];

int find(int x) {
    if (x == f[x]) return x;
    int root = find(f[x]);
    d[x] = (d[x] + d[f[x]]) % 3;
    return f[x] = root;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i, d[i] = 0;
    for (int i = 1; i <= m; i++) {
        int opt, u, v; cin >> opt >> u >> v;
        if (u > n or v > n) {ans++; continue;}
        if (opt == 2 and u == v) {ans++; continue;}
        int fu = find(u), fv = find(v);
        switch (opt) {
            case 1:
                if (fu == fv and d[u] != d[v]) {ans++; continue;}
                else if (fu != fv) {
                    f[fu] = fv;
                    d[fu] = (3 - d[u] + d[v]) % 3;
                }
            break;
            case 2:
                if (fu == fv) {
                    int t = (d[u] - d[v] + 3) % 3;
                    if (t != 1) {ans++; continue;}
                } else {
                    f[fu] = fv;
                    d[fu] = (3 - d[u] + d[v] + 1) % 3;
                }
            break;
        }
    }
    cout << ans << endl;
}




