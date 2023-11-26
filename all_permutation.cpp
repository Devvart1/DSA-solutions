#include<bits/stdc++.h>

using namespace std;
void perm(char *in,int i)
{
    if(in[i]=='\0')
    {
        in[i]='\0';
        cout<<in<<" ";
        return ;

    } 
    for(int j=i;in[j]!='\0';++j)
    {
           swap(in[i],in[j]);
           perm(in,i+1);
           swap(in[i],in[j]);
    }
}
void uniq_perm(char *in,int i,set<string> &s)
{
    if(in[i]=='\0')
    {
        string t(in);
        s.insert(t);
        return ;

    } 
    for(int j=i;in[j]!='\0';++j)
    {
           swap(in[i],in[j]);
           uniq_perm(in,i+1,s);
           swap(in[i],in[j]);
    }
}
int main()
{
    char x[]="ddd";
    set<string> s;

perm(x,0);
uniq_perm(x,0,s);
cout<<"\n";
for(auto c:s)
cout<<c<<" ";


}