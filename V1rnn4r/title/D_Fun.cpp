#include "Monday.h"

using namespace virmar;

void doit() {
    int n, x; cin >> n >> x;
    ll ans = 0;
    for (int a = 1; a <= min(n, x); a++)
        for (int b = 1; a * b <= n and a + b <= x; b++) {
            int c = min((n - a * b) / (a + b), x - (a + b));
            ans += c;
        }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}