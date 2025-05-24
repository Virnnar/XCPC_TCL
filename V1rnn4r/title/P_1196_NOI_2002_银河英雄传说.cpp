#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 3E4 + 6;

int n;
int f[N], siz[N], d[N];

int find(int x) {
    if (x == f[x]) return x;
    int root = find(f[x]);
    d[x] += d[f[x]];
    return f[x] = root;
}

int main() {
    cin >> n;
    for (int i = 1; i <= 30000; i++) f[i] = i, d[i] = 0, siz[i] = 1;
    for (int i = 1; i <= n; i++) {
        char opt; int u, v;
        cin >> opt >> u >> v;
        int fu = find(u), fv = find(v);
        switch (opt) {
            case 'M':
                f[fu] = fv;
                d[fu] += siz[fv];
                siz[fv] += siz[fu];
                siz[fu] = 0;
                break;
            case 'C': 
                cout << (fu == fv ? abs(d[u] - d[v]) - 1 : -1) << endl;
        }
    }
}

