// program to convert plaintext to caesar cipher text

#include <bits/stdc++.h>
using namespace std;

int main(int argv,char** args)
{
    char* out=new char[strlen(args[1])];
    int i;
    for(i=0;i<strlen(args[1]);i++)
    {
        if(args[1][i]==' ')
        {
            args[1][i]-=3;
        }
        if(toupper(args[1][i])>'A'+22)
        {
            args[1][i]-=26;
        }
        out[i]=(args[1][i]+3);
    }
    out[i]='\0';
    cout<<out<<endl;
    return 0;
}
