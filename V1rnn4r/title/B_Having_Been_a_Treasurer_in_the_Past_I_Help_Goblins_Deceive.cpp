#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    string s; cin >> s;
    ll cnt1 = 0, cnt2 = 0;
    for (auto i: s)
        i == '_' ? cnt1++ : cnt2++;
    cout << (cnt2 / 2 * (cnt2 - cnt2 / 2)) * cnt1 << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}