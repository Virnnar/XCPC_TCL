#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    if (count(all(a), 1) == n) return puts("YES"), void();
    for (int i = 0; i < n - 1; i++)
        if (a[i] == 0 and a[i + 1] == 0)
            return puts("YES"), void();
    puts("NO");

}

int main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

void init() {

}