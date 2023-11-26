#include<bits/stdc++.h>
using namespace  std;


int sack(int *wt,int *price ,int cap,int i)
{
if(cap<=0||i==0)
{
  return 0;
}
int x=INT_MIN;
if((wt[i-1])<=cap)
x=price[i-1] + sack(wt,price,cap-wt[i-1],i-1);
int y=sack(wt,price,cap,i-1);
return max(x,y);
}
int main()
{int n=4;
int price[n]={40,20,30,100};
int wt[n]={1,2,3,5};
cout<<sack(wt,price,7,n);

}