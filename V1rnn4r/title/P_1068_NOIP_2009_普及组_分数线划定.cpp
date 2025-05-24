#include "Monday.h"

using namespace virmar;

const int N = 100000;

struct node{
    int k, s;
};

node a[N];

bool cmp(node p, node q) {
    if (p.s == q.s) return p.k < q.k;
    return p.s > q.s;
}

int n, m;

void doit() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].k >> a[i].s;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << a[i].k << ' ' << a[i].s << endl;
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1;// cin >> T;
    while (T--) doit();
    return 0;
}