#include "Monday.h"

using namespace virmar;

const int N = 2E5 + 6;

int n, m;
string a, b;
int sa[N][30], sb[N][30];

void doit() {
    cin >> n >> m >> a >> b;
    mset(sa, 0), mset(sb, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++) {
            sa[i + 1][j] = sa[i][j] + (a[i] == j + 'a');
            sb[i + 1][j] = sb[i][j] + (b[i] == j + 'a');
        }
    while (m--) {
        int l, r, d = 0; cin >> l >> r;
        for (int j = 0; j < 26; j++)
            d += abs((sa[r][j] - sa[l - 1][j]) - (sb[r][j] - sb[l - 1][j]));
        cout << d / 2 << endl;
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}