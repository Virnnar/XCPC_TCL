#include<iostream>

using namespace std;

const int N = 10;

int n;
int a[N];

int main() {
    while (cin >> n) {
        for (int i = n; i >= 0; i--) cin >> a[i];
        int ans = 0, x;
        cin >> x;
        a[n + 1] = 0;
        for (int i = n + 1; i >= 0; i--)
            ans = ans * x + a[i];
        cout << ans << endl;
    }
}
