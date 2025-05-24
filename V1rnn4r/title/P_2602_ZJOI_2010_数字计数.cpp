#include "Monday.h"

using namespace virmar;

const int N = 50;

ll a, b;
ll f[N], ten[N];
ll cnta[20], cntb[20];

void handle(ll t, ll cnt[]) {
    vector<int> num;
    while (t) num.push_back(t % 10), t /= 10;

    for (int i = num.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 10; j++) cnt[j] += f[i] * num[i];
        for (int j = 0; j < num[i]; j++) cnt[j] += ten[i];

        ll temp = 0;
        for (int j = i - 1; j >= 0; j--) {
            temp = temp * 10 + num[j];
        }
        cnt[num[i]] += temp + 1;
        cnt[0] -= ten[i];
    }
}

void init() {
    ten[0] = 1;
    for (int i = 1; i <= 15; i++) {
        f[i] = f[i - 1] * 10 + ten[i - 1];
        ten[i] = 10 * ten[i - 1];
    }
}

void doit() {
    init();
    cin >> a >> b;
    handle(a - 1, cnta);
    handle(b, cntb);
    for (int i = 0; i < 10; i++)
        cout << cntb[i] - cnta[i] << ' ';
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}