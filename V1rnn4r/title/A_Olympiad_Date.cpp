#include "Monday.h"

using namespace virmar;

void doit() {
    vector<int> cnt(10), ans(10);
    int d[] = {0, 1, 2, 3, 5};
    ans[0] = 3, ans[1] = 1, ans[2] = 2, ans[3] = 1, ans[5] = 1;
    int n; cin >> n;
    int res = 0;

    auto jud = [&]() -> bool {
        for (auto id: d)
            if (cnt[id] < ans[id])
                return false;
        return true;
    };

    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        cnt[t]++;
        if (jud() and res == 0) res = i;
    }
    cout << res << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}