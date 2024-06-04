#include<iostream>
using namespace std;
const int N=1000010,mod=10000;
int f[N],g[N];
int main(){
    int n;
    cin>>n;
    f[0]=1,g[0]=0;
    g[1]=1,f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2]+2*g[i-2]%mod;
        g[i]=(f[i-1]+g[i-1])%mod;
    }
    cout<<f[n]%mod<<endl;
    return 0;
}