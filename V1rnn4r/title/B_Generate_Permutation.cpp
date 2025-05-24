#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    if (n % 2 == 0) return puts("-1"), void();
    vector<int> a(n + 1);
    a[n / 2 + 1] = 1;
    for (int d = 1; d <= n / 2; d++)
        a[n / 2 + 1 + d] = 2 * d, a[n / 2 + 1 - d] = 2 * d + 1;
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}