#include "Monday.h"

using namespace virmar;

void doit() {
    int n, C; cin >> n >> C;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int cnt = 0, lt = -INF;
    for (auto i: a)
        if (i - lt >= C)
            cnt++, lt = i;
    cout << cnt << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1;// cin >> T;
    while (T--) doit();
    return 0;
}