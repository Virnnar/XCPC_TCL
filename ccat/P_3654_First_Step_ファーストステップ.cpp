#include<iostream>
using namespace std;
const int N=110;
char map[N][N];
int main(){
    int r,c,k;
    cin>>r>>c>>k;
    for(int i=0;i<r;i++) cin>>map[i];
    int cnt_r=0,cnt_c=0,res=0;
    for(int i=0;i<r;i++){
        cnt_r=0;
        for(int j=0;j<c;j++){
            if(map[i][j]=='.') cnt_r++;
            else {
                if(cnt_r>=k) res+=cnt_r-k+1;
                // cout<<cnt_r<<" ";
                cnt_r=0;
            }
        }
        if(cnt_r>=k) res+=cnt_r-k+1;
        // cout<<endl;
    }
    for(int j=0;j<c;j++){
        cnt_c=0;
        for(int i=0;i<r;i++){
            if(map[i][j]=='.') cnt_c++;
            else {
                if(cnt_c>=k) res+=cnt_c-k+1;
                // cout<<cnt_c<<" ";
                cnt_c=0;
            }
        }
        if(cnt_c>=k) res+=cnt_c-k+1;
        // cout<<endl;
    }
    if(k==1) cout<<res/2<<endl;
    else cout<<res<<endl;
    return 0;
}