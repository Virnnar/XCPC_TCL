#include "Monday.h"

using namespace virmar;

void doit() {
    int n = read<int>();
    vector<int> a(n), b(n - 1);
    for (auto &i: b) i = read<int>();
    for (int j = 0; j < 30; j++) {
        for (int i = 0; i < n - 1; i++)
            if (b[i] >> j & 1)
                a[i] |= 1 << j, a[i + 1] |= 1 << j;
        for (int i = 0; i < n - 1; i++)
            if ((b[i] >> j & 1) == 0) {
                if ((a[i] >> j & 1) and (a[i + 1] >> j & 1)) return puts("-1"), void();
            }
    }
    for (auto i: a) cout << i << ' ';
    cout << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}