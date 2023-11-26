
#include<bits/stdc++.h>

using namespace std;

// // int sol(int n,int j,vector<vector<int>> p,vector<vector<int>> &dp)
// // {
// //       if(dp[n][j]!=-1)
// //             return dp[n][j];
// //     if(n==0)
// //     {
// //         int maxi=0;
        
// //         for(int i =0;i<=2;++i)
// //         {
// //             if(i!=j)
// //             {
// //                 maxi= max(maxi,p[0][i]);
// //             }
           
// //         }
// //          return maxi;
// //     }
  
// //     int maxi=0;
// //     int point;
// //     for(int i =0;i<= 2;++i)
// //     {
        
        
// //         if(i!=j)
// //         {
            
// //           point= p[n][i] + sol(n-1,i,p,dp) ;
// //                   maxi=max(maxi,point);
// //         }
      
// //     }
// //     return dp[n][j]=maxi;
    
// // }
int ninjaTraining(int n, vector<vector<int>> &points)
// { 
// //     vector<vector<int>> dp(n,vector<int> (4,-1));
    
    
// //    return sol(n-1,3,points,dp);
    
    
// //    vector < vector < int > > dp(n, vector < int > (4, 0));

// //   dp[0][0] = max(points[0][1], points[0][2]);
// //   dp[0][1] = max(points[0][0], points[0][2]);
// //   dp[0][2] = max(points[0][0], points[0][1]);
// //   dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

// //   for (int day = 1; day < n; day++) {
// //     for (int last = 0; last < 4; last++) {
// //     // dp[day][last] = 0;
// //       for (int task = 0; task <= 2; task++) {
// //         if (task != last) {
// //           int activity = points[day][task] + dp[day - 1][task];
// //           dp[day][last] = max(dp[day][last], activity);
// //         }
// //       }
// //     }

// //   }

// //   return dp[n - 1][3];
     vector < int> prev(4);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
      vector<int> temp(4,0);
    for (int last = 0; last < 4; last++) {
   temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
         
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }
prev=temp;
  }

  return prev[3];
}


int main() {

  vector<vector<int> > points = {{10,40,70},
                                 {20,50,80},
                                 {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}


