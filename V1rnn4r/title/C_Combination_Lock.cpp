#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    if (n % 2 == 0) return puts("-1"), void();

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        a[2 * i % n] = i;
    for (int i = 0; i < n; i++)
        cout << a[i] + 1 << ' ';
    cout << endl;
}


int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}