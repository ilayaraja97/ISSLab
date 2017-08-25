// Program to convert hillciphertext to plaintext 
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<" = "<<x<<endl

int main(int argv,char** args)
{
    const int key[3][3]={{0,1,-2},{1,0,-1},{-3,-2,8}};
    string ciphertext1=args[1],plaintext="";
    assert(ciphertext1.length()<142);
    int ct[145]={0}; //why 144? i encrypt tweets!
    for(uint i=0;i<ciphertext1.length();i++)
    {
        ct[i]=ciphertext1[i]-'a';
    }
    int temp[3],mult[3];
    for(uint n=0;n<ciphertext1.length();n+=3)
    {
        temp[0]=ct[n];
        temp[1]=ct[n+1];
        temp[2]=ct[n+2];
        mult[0]=mult[1]=mult[2]=0;
        for(int j = 0; j < 3; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                mult[j] += temp[k] * key[k][j];
            }
        }
        // mult[x]<0?26-mult[x]%26:mult[x]%26
        plaintext.push_back(mult[0]<0?26+mult[0]%26+'a':mult[0]%26+'a');
        plaintext.push_back(mult[1]<0?26+mult[1]%26+'a':mult[1]%26+'a');
        plaintext.push_back(mult[2]<0?26+mult[2]%26+'a':mult[2]%26+'a');
    }
    cout<<plaintext<<endl;
    return 0;
}
