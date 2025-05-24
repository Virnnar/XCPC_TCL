#include<iostream>

using namespace std;

int n;
int a[1010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        a[t]++;
    }
    int ans = 0;
    while (a[0] != 0) {
        int i = 0;
        while (a[i] != 0) a[i]--, i++;
        ans += i;
    }
    cout << ans << endl;
}