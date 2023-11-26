#include<bits/stdc++.h>
using namespace  std;


void subset(char *in,char *out,int i,int j)
{
if(in[i]=='\0')
{
    out[j]='\0';
    cout<<out<<" ";
    return;
}
//include curr char
out[j]=in[i];
subset(in ,out,i+1,j+1);
//exchulte curr char
subset(in,out,i+1,j);
 
}
int main()
{
char in[]="abs";
char out[10];
subset(in,out,0,0);
}