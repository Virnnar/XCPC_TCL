#include "Monday.h"

using namespace virmar;

void doit() {
    int n = read<int>();
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        int u = read<int>(), v = read<int>();
        x = max(x, u), y = max(y, v);
    }
    cout << ((x + y) << 1) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}