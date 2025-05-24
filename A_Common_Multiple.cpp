#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(all(a));
    int ans = distance(a.begin(), unique(all(a)));

    cout << ans << endl;
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