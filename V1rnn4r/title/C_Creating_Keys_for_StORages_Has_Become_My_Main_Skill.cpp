#include "Monday.h"

using namespace virmar;

void doit() {
    int n, x; cin >> n >> x;
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if ((x | i) == x)
            ans.push_back(i);
    while (ans.size() < n) ans.push_back(x);
    if (accumulate(all(ans), 0, [&](int i, int j){return i | j;}) != x)
        ans.back() = x;
    for (auto i: ans) cout << i << ' ';
    puts("");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}