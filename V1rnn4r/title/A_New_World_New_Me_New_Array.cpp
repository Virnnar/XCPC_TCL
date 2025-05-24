#include "Monday.h"

using namespace virmar;

void doit() {
    int n, k, p;
    cin >> n >> k >> p;
    k = abs(k);
    if (k > n * p) return puts("-1"), void();
    cout << ((k + p - 1) / p) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}