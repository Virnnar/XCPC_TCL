#include "Monday.h"

using namespace virmar;

void doit() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> a(n, 1);
    if (0 <= x + 1 and x + 1 < n) a[x + 1] = -1;
    for (int i = x + 2; i < n; i++) a[i] = -a[i - 1];
    if (0 <= y - 1 and y - 1 < n) a[y - 1] = -1;
    for (int i = y - 2; i >= 0; i--) a[i] = -a[i + 1];
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}