#include "Monday.h"

using namespace virmar;

const int N = 1E3 + 6;

int n, k;
string a[N];

void doit() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n / k; i++, puts(""))
        for (int j = 0; j < n / k; j++)
            cout << a[i * k][j * k];
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}