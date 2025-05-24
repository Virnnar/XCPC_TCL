#include "Monday.h"

using namespace virmar;

void doit() {
    int l, r, L, R; cin >> l >> r >> L >> R;
    int inner = min(r, R) - max(l, L);
    if (inner < 0) return puts("1"), void();
    cout << inner + (l != L) + (r != R) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}