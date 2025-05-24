#include "Monday.h"

using namespace virmar;

int l, r;
int f[20][20];

void init() {
    for (int i = 0; i < 10; i++) f[1][i] = 1;
    for (int i = 2; i <= 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                f[i][j] += abs(j - k) >= 2 ? f[i - 1][k] : 0;
}

int digital(int x) {
    int res = 0;
    vector<int> a;
    while (x) a.push_back(x % 10), x /= 10;
    for (int i = 1; i < a.size(); i++)
        for (int j = 1; j <= 9; j++)
            res += f[i][j];
    for (int j = 1; j < a.back(); j++)
        res += f[a.size()][j];

    for (int i = a.size() - 2; i >= 0; i--) {
        for (int j = 0; j < a[i]; j++)
            if (abs(j - a[i + 1]) >= 2) res += f[i + 1][j];
        if (abs(a[i + 1] - a[i]) < 2) break;
    }
    return res;
}

void doit() {
    cin >> l >> r;
    // cout << digital(r + 1) - digital(l) << endl;
    cout << digital(8432)  << endl;
    // cout << digital(7999) << endl;
    // cout << digital(8432) - digital(7999) << endl;
}

int main() {
    init();
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}

// 8319