#include "Monday.h"

using namespace virmar;

void doit() {
    int n, m, q; cin >> n >> m >> q;
    int a, b; cin >> a >> b;
    int p; cin >> p;
    if (a > b) swap(a, b);
    if (a < p and p < b) cout << (b - a) / 2 << endl;
    else if (p < a) cout << a - 1 << endl;
    else cout << n - b << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}
