#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    ll ans = a[0] / 2, p = 2;
    for (int i = 1; i < n; i++)
        a[i] = (a[i] + a[i - 1]) / 2;
    cout << a.back() << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

// 1 4 5 7 8

