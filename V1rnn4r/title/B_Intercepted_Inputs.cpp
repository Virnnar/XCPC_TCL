#include "Monday.h"

using namespace virmar;

void doit() {
    int k; cin >> k;
    vector<int> a(k + 1);
    for (int i = 0; i < k; i++) {
        int t; cin >> t;
        a[t]++;
    }
    for (int i = 1; i <= k; i++) {
        if ((k - 2) % i or a[i] == 0) continue;
        a[i]--;

        if (a[(k - 2) / i])
            return cout << i << ' ' << (k - 2) / i << endl, void();

        a[i]++;
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}