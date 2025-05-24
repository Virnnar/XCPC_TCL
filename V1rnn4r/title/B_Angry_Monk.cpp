#include "Monday.h"

using namespace virmar;

int n, k;

void doit() {
    cin >> n >> k;
    vector<int> a(k);
    for (auto &i: a) cin >> i;
    auto p = max_element(a.begin(), a.end());
    auto it = a.begin();
    ll ans = 0;
    while (it != a.end()) {
        if (it != p) ans += *it * 2 - 1;
        it++;
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}