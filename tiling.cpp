#include<bits/stdc++.h>
using namespace std;
int tiling(int n)
{
if(n<=3)
return 1;

return tiling(n-1) +tiling(n-4);
}
int main()
{

    cout<<tiling(6);

}