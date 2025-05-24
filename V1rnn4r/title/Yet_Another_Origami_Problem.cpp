#include "Monday.h"

using namespace virmar;

const int N = 1E5 + 6;

int n;
ll a[N];

void doit() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) return puts("0"), void();
    ll ans = 0x3f3f3f3f;
    for (int i = 2; i < n; i++) ans = min(ans, gcd<ll>(llabs(a[i] - a[i - 1]), ans));
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}