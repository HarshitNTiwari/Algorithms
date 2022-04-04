#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);
int minN(int n, int m, int k);

int main(){
    int n; cin>>n;
    int x,y,z;
    cin>>x>>y>>z;

    cout<< maximizeTheCuts(n,x,y,z);
}


int minN(int n, int m, int k){
    if(n<=m && n<=k)
        return n;
    else if(m<=n && m<=k)
        return m;
    else if(k<=n && k<=m)
        return k;
}

int maximizeTheCuts(int n, int x, int y, int z){
    vector<int> cuts{x,y,z};
    // sort(cuts.begin(),cuts.end());
    int d = cuts.size();
    vector<vector<int>> dp(d+1, vector<int> (n+1,-1));
    vector<int> val{1,1,1};

    for(int i=0;i<cuts.size();i++){
        cout<<cuts[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<=d;i++)
        for(int j=0;j<=n;j++)
            if(i==0 || j==0) 
                dp[i][j]=0;
    dp[0][0]=1;
    for(int i=1;i<=d;i++){  
        for(int j=1;j<=n;j++){
            if(cuts[i-1]<=j && ((j-cuts[i-1]>=minN(x,y,z)) || j-cuts[i-1]==0))
                dp[i][j]= max(val[i-1]+ dp[i][j-cuts[i-1]], dp[i-1][j]);
            else
                dp[i][j]= dp[i-1][j];
        }
    }
    
    for(int i=0;i<=d;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[d][n]; 
}