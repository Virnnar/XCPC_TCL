#include<iostream>
#include<cstring>

using namespace std;
using ll = long long;

const int N = 5E5 + 6;
const int MOD = 1E9 + 7;

int n;
ll s[N], idx;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, v; cin >> t >> v;
        idx -= t;
        ++idx;
        s[idx] = (s[idx - 1] + v * idx % MOD) % MOD;
        cout << s[idx] % MOD << endl;
    }
    return 0;
}

