#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    vector<int> cnt(n + 1);
    for (auto i: a)
        cnt[i]++;
    for (auto i: cnt)
        if (i & 1) return void(puts("YES"));
    puts("NO");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}