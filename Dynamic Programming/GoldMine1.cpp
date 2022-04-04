#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


    int maxN(int n, int m){
        return (n > m) ? n : m;
    }
    int max3(int n, int m, int k){
        if(n>=m && n>=k)
            return n;
        else if(m>=n && m>=k)
            return m;
        else if(k>=n && k>=m)
            return k;
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans=0;
        int k=0;
        for(int i=0;i<n;i++){
            int temp =ans;
            ans= maxN(ans,M[i][0]);
            if(ans!=temp)
                k=i;
        }
        
        for(int i=1;i<m;i++){
            int temp=0;
            if(k==0)
                temp= maxN(M[k][i],M[k+1][i]);
            else if(k==n-1)
                temp= maxN(M[k][i],M[k-1][i]);
            else 
                temp= max3(M[k][i],M[k-1][i],M[k+1][i]);
            if(k>0 && temp==M[k-1][i])
                k=k-1;
            else if(k<n-1 && temp==M[k+1][i])
                k=k+1;
            ans=ans+ temp;
        }
        return ans;
    }