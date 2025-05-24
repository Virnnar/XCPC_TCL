#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b.begin(), b.end());

    map<int, int> H;
    for (int i = 1; i <= n; i++) H[b[i]] = i;
    for (int i = 1; i <= n; i++) a[i] = H[a[i]];

    BinaryIndexedTree<int> BIT;
    BIT.init(n + 5);

    int ans = 0;
    for (int i = n; i >= 1; i--) {
        BIT.add(a[i], 1);
        ans = max(ans, BIT.get(a[i]));
    }
    cout << n - ans << endl;
}



int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}