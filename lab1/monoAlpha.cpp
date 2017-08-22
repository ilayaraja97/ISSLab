// Program to convert plaintext to monoalphabetic cipher
#include <bits/stdc++.h>
using namespace std;

int main(int argv,char** args)
{
    const char dictionary[27]="thequickbrownfxjmpsvlazydg";
    string ciphertext=args[1];
    for(unsigned int i=0;i<strlen(args[1]);i++)
    {
        ciphertext[i]=dictionary[tolower(args[1][i])-'a'];
    }
    cout<<ciphertext<<endl;
    return 0;
}
