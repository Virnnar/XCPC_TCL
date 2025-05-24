#include "Monday.h"

using namespace virmar;

void doit() {
    auto check = [&](ll t) {
        ll j = sqrtl(t);
        return j * j == t;
    };

    ll n; cin >> n;
    if (check(n * (n + 1) / 2)) return puts("-1"), void();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = i;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        if (check(sum)) swap(a[i], a[i + 1]);
        cout << a[i] << ' ';
    }
    puts("");

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}