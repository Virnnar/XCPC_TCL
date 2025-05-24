#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    sort(all(a));
    int max_val = 0; // 记录前面的数字增加到多少
    for (int i = 0; i < n; i += 2) {
        if (max(max_val, a[i]) != max(max_val, a[i + 1])) return puts("No"), void();
        max_val = max(max_val, a[i]) + 1;
    }
    puts("Yes");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}


