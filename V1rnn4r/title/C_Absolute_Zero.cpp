#include "Monday.h"

using namespace virmar;

void doit() {
    int n = read<int>();
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    bool odd = false, even = false;
    for (auto i: a)
        if (i & 1) odd = true;
        else even = true;
    if (odd and even) return puts("-1"), void();
    cout << (30 + even) << endl;
    for (int i = 29; i >= 0; i--)
        cout << (1 << i) << ' ';
    if (even) cout << 1;
    puts("");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}