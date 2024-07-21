#include "Monday.h"

using namespace virmar;

const int N = 1E5 + 6;

int n;
int a[N], f[N];

void doit() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        f[i] = max(a[i], f[i + 1] + 1);

    cout << *minmax_element(f + 1, f + n + 1).second << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}



