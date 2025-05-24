#include "Monday.h"

using namespace virmar;

void doit() {
    int n, k, ans = 0; 
    cin >> n >> k;
    if (k == 1) return cout << n << endl, void();
    while (n) {
        ans += n % k;
        n /= k;
    }
    cout << ans << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}