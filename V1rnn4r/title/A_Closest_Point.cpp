#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    return puts(n == 1 or (n == 2 and abs(a[0] - a[1]) > 1) ? "YES" : "NO"), void();
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}