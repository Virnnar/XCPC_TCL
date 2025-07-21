#include<iostream>
#include<string>

using namespace std;

int a[100001];
int f[100001];

int dfs(int i) {
    int res = 0;
    for (int j = 1; j < i; j++)
        if (a[j] < a[i])
            res = max(res, dfs(j) + 1);
    return res;
}

for (int i = 1; i <= n; i++) {
    f[i] = 1;
    for (int j = 1; j < i; j++)
        if (a[j] < a[i])
            f[i] = max(f[i], f[j] + 1);
    
}

int main() {

}


