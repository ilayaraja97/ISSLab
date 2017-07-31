// program to convert plaintext from caesar cipher text with key text

#include <bits/stdc++.h>
using namespace std;

int main(int argv,char** args)
{
    char* out=new char[strlen(args[1])];
    
    int i,k;
    for(i=0;i<strlen(args[1]);i++)
    {
        k=toupper(args[2][i%4])-'A';
        k-=26;
		if(k<0)
		{
			k*=-1;
		}
        if(args[1][i]==' ')
        {
            args[1][i]-=k;
        }
        if(toupper(args[1][i])>'A'+26-k-1)
        {
            args[1][i]-=26;
        }
        out[i]=(args[1][i]+k);
    }
    out[i]='\0';
    cout<<out<<endl;
    return 0;
}
