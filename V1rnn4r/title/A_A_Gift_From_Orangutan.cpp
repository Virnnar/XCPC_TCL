#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    int min_val = INF, max_val = 0;
    for (int i = 0; i < n; i++) {
        int t = read<int>();
        min_val = min(min_val, t);
        max_val = max(max_val, t);
    }
    cout << (max_val - min_val) * (n - 1) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}