#include "Monday.h"

using namespace virmar;

const int N = 1E6 + 6, M = N << 1;

struct {
    int next, to, val;
} e[M];
int head[N], num;

void add(int from, int to, int val) {
    e[num] = {head[from], to, val};
    head[from] = num++;
}

int n;
int c[N], ans[N];

void doit() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v >> c[i];
        add(u, v, i);
        head[i] = -1;
    }
    head[n] = -1;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}