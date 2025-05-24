#include "Monday.h"

using namespace virmar;

ll n, m, a, b;

ll ex_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = ex_gcd(b, a % b, x, y);
    ll temp = x;
    x = y;
    y = temp - a / b * y;
    return d;
}

void doit() {
    cin >> n >> m >> a >> b;
    if (n * m % 2 == 1) return puts("No"), void();
    if (n * m == 2) return puts("Yes"), void();
    if (a == 0 and b == 0)
        return puts("No"), void();
    if (a == 0 and b == 1) {
        if (n == 1 or m == 1) return puts("No"), void();
        return puts("Yes"), void();
    }
    if (a == 1 and b == 0)
        return puts((n == 1 or m == 1) ? "Yes" : "No"), void();
    puts("Yes");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}


