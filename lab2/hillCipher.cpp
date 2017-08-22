// Program to convert plaintext to hillciphertext
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<" = "<<x<<endl

int main(int argv,char** args)
{
    const int key[3][3]={{2,4,1},{5,6,2},{2,3,1}};
    string plaintext=args[1],ciphertext="";
    int pt[144]={0}; //why 144? i encrypt tweets!
    for(uint i=0;i<plaintext.length();i++)
    {
        pt[i]=plaintext[i]-'a';
    }
    int temp[3],mult[3];
    for(uint n=0;n<plaintext.length();n+=3)
    {
        temp[0]=pt[n];
        temp[1]=pt[n+1];
        temp[2]=pt[n+2];
        mult[0]=mult[1]=mult[2]=0;
        for(int j = 0; j < 3; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                mult[j] += temp[k] * key[k][j];
            }
        }
        ciphertext.push_back(mult[0]%26+'a');
        ciphertext.push_back(mult[1]%26+'a');
        ciphertext.push_back(mult[2]%26+'a');
    }
    cout<<ciphertext<<endl;
    return 0;
}
