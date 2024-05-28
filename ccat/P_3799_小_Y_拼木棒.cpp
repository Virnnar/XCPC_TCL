#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;
const int N=1e6+7;
const LL mod=1e9+7;
int a[N],num[N];
LL culc(int n,int k){
    if(k==1) return (LL)n%mod;
    else{
        return n*(n-1LL)/2%mod;
    }
}
int main(){
    int n,mx;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        num[a[i]]++;
        mx=max(mx,a[i]);
    }
    LL ans=0;
    for(int i=2;i<=mx;i++){
        if(num[i]>=2){
            LL times=culc(num[i],2)%mod;
            for(int j=1;j<=i/2;j++){
                if(j!=i-j&&num[j]>=1&&num[i-j]>=1) ans+=times*culc(num[j],1)*culc(num[i-j],1)%mod;
                if(j==i-j&&num[j]>=2) ans+=times*culc(num[j],2)%mod;
                ans%=mod;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}