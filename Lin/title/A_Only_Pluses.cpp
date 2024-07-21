#include "Monday.h"

using namespace virmar;

void doit() {
    vector<int> a(3);
    for (auto &i: a) cin >> i;
    int cnt = 5;
    while (cnt --> 0) {
        (*min_element(a.begin(), a.end()))++;
    }
    ll ans = 1;
    for (auto i: a) ans *= i;
    // cout << endl;
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}
