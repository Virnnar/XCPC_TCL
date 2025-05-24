#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    if (n <= 4) return puts("-1"), void();
    vector<int> ans;
    for (int i = 1; i <= n; i += 2)
        if (i != 5) ans.push_back(i);
    ans.push_back(5);
    ans.push_back(4);
    for (int i = 2; i <= n; i += 2)
        if (i != 4) ans.push_back(i);
    for (auto i: ans) cout << i << ' ';
    cout << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}
