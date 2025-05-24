#include "Monday.h"

using namespace virmar;

void doit() {
    int n, k;
    cin >> n >> k;
    puts(((n + 1) * n / 2 - (n - k) * (n - k + 1) / 2) % 2 ? "NO" : "YES");
}

// 1 0 1 0


int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

