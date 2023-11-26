#include<bits/stdc++.h>
using namespace  std;


void bracket(char *out,int i,int o,int c,int n)
{
if(i==n*2)
{
    out[i]='\0';
    cout<<out<<endl;
    return;
}
//include curr cha
if(o<n){
out[i]='(';
bracket(out,i+1,o+1,c,n);
} 
if(c<o){
out[i]=')';
bracket(out,i+1,o,c+1,n);
}
}
int main()
{
char in[40];

bracket(in,0,0,0,3);
}