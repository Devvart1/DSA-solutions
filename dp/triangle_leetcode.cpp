#include <bits/stdc++.h>
using namespace std;
  
  
  int minimumTotal(vector<vector<int>>& triangle) {

     int n=triangle.size();
   //  vector<vector<int>> dp(n,vector<int> (triangle[n-1].size(),-1));

int m=triangle[n-1].size();

vector<int> prev(m,0);
     vector<vector<int>> dp(n,vector<int> (m,0));

  
         for(int i=0;i<m;++i)
         {
            prev[i]=triangle[n-1][i];
         }
    for(int i =n-2;i>=0;--i)
    {
        vector<int> curr(m,0);
        for( int j=0;j<=triangle[i].size()-1;++j)
        {
             
       

 
    curr[j]=min(prev[j+1],prev[j]) + triangle[i][j];


               

        }
        prev=curr;
    }


     /// return sol(0,0,n,triangle,dp);
   return prev[0];
    }

    int main()
    {


        return 0;
    }