#include "Monday.h"

using namespace virmar;

void doit() {
    int x, y, k; cin >> x >> y >> k;
    int cntx = (x + k - 1) / k, cnty = (y + k - 1) / k;
    if (cnty >= cntx) cout << cnty * 2 << endl;
    else cout << 2 * (cntx - 1) + 1 << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}