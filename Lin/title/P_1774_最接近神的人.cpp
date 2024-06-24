#include "Monday.h"

using namespace virmar;

BinaryIndexedTree<ll> BIT;

const int N = 5E5 + 6;

int n;
ll ans = 0;
ll a[N], b[N];

void discret() {
    for (int i = 1; i <= n; i++) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (b[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }
        a[i] = l;
    }
}

void doit() {
    cin >> n;
    BIT.init(5E5 + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    discret();
    for (int i = 1; i <= n; i++) {
        ans += BIT.get(5E5) - BIT.get(a[i]);
        BIT.add(a[i], 1);
    }
    cout << ans << endl;

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}