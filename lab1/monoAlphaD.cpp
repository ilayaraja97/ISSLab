// Program to convert plaintext to monoalphabetic cipher
#include <bits/stdc++.h>
using namespace std;

bool crack(string ct);
string actualpt="zzzz";
int main()
{
    //const char dictionary[27]="thequickbrownfxjmpsvlazydg";
    //string ciphertext=args[1];
    //for(unsigned int i=0;i<strlen(args[1]);i++)
    //{
        //ciphertext[i]=dictionary[tolower(args[1][i])-'a'];
    //}
    //cout<<ciphertext<<endl;
    cout<<crack("gggg");
    return 0;
}

bool crack(string ct)
{
    long count=0;
    for(char n1='a';n1<='z';n1++)
    {
        if(n1!=ct[0])
        for(char n2='a';n2<='z';n2++)
        {
            if(n2!=ct[1])
            for(char n3='a';n3<='z';n3++)
            {
                if(n3!=ct[2])
                for(char n4='a';n4<='z';n4++)
                {
                    if(n4!=ct[3])
                    {
                        count++;
                        if(n1==actualpt[0]&&n2==actualpt[1]&&n3==actualpt[2]&&n4==actualpt[3])
                        {   
                            cout<<actualpt<<" cracked in "<<count<<" counts"<<endl;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
        
