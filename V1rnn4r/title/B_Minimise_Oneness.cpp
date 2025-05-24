#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) cout << 0;
    // if (n & 1) cout << 1;
    cout << 1;
    cout << endl;
}

// a, b

// 2 ^ a - 1
// (2 ^ b - 1) * (2 ^ a - 1)

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}