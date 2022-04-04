
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxGold(int n, int m, vector<vector<int>> M);
int maxtwo(int n, int m);
int maxthree(int n, int m, int k);


int main(){
    int n; cin>>n;
    int m; cin>>m;

    vector<vector<int>> M(n+1, vector<int> (n+1,0));

    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            int k; cin>>k;
            M[i].push_back(k);
        }
    }
                                        
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<maxGold(n,m,M)<<endl;

    return 0;
}

int maxtwo(int n, int m){
    return (n > m) ? n : m;
}
int maxthree(int n, int m, int k){
    if(n>=m && n>=k)
        return n;
    else if(m>=n && m>=k)
        return m;
    else if(k>=n && k>=m)
        return k;
}
int maxGold(int n, int m, vector<vector<int>> M){
    // for(int i=0; i<n;i++){
    //     for(int j=0; j<m;j++){
    //         cout<<M[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int ans=0;
    int k=0;
    for(int i=0;i<n;i++){
        int temp =ans;
        int t = M[i][0];
        ans= maxtwo(temp,t);
        cout<<"ans: "<<ans<<endl;
        if(ans!=temp){
            cout<<"YES"<<endl;
            k=i;
        }
        cout<<"k: "<<k<<endl;
    }
    // cout<<"k: "<<k<<endl;
    for(int i=1;i<=m;i++){
        int temp=0;
        int t= M[k][i];
        if(k==0){
            int y=M[k+1][i];
            temp= maxtwo(t,y);
        }
        else if(k==n-1){
            int y= M[k-1][i];
            temp= maxtwo(t,y);
        }
        else{ 
            int y= M[k-1][i];
            int z= M[k+1][i];
            temp= maxthree(t,y,z);
        }
        if(k!=0 && temp==M[k-1][i])
            k=k-1;
        else if(k!=n-1 && temp==M[k+1][i])
            k=k+1;
        ans=ans+ temp;
    }
    return ans;
}