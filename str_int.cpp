#include<bits/stdc++.h>
using namespace std;

int stringtoint(char *a,int n)
{

     if(n==0)
     return 0;
      int x=a[n-1]-'0';
     int y=stringtoint(a,n-1);
     return y*10+x;
}
int main()
{
 

char s[]="123405";

int n=strlen(s);

int x;
x=stringtoint(s,n);
cout<<x;
    return 0;

}