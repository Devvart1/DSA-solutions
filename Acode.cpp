#include<bits/stdc++.h>
using namespace  std;


void Acode(char *code,char *out,int i,int j )
{
   if(code[i]=='\0')
   {
    out[j]='\0';
    cout<<out<<endl;
    return;
   }

   int digit=code[i]-'0';
   char x=digit +'A'-1;
   out[j]=x; 
   Acode(code,out,i+1,j+1);
   if(code[i+1]!='\0')
   {
    int y=code[i+1]-'0';
 int nd=digit*10 +y ;
 if(nd<=26)
 {
    char ch=nd+'A'-1;
    out[j]=ch; 
   Acode(code,out,i+2,j+1);

 }
    
   }
}

int main()
{


   int n=3;
    char code[n]="1234";
char out[100];
Acode(code,out,0,0);

}