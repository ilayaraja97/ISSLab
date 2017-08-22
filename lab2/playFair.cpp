// Program to convert plaintext to playfair ciphertext
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<" = "<<x<<endl
void findposIn(const char mat[5][6],char c,int &x,int &y)
{
    for(x=0;x<5;x++)
    {
        for(y=0;y<5;y++)
        {
            if(mat[x][y]==c||(c=='j'&&mat[x][y]=='i'))
            {
                return;
            }
        }
    }
}

int main(int argv,char** args)
{
    const char mat[5][6]={"helow","rldab","czfgi","kympq","stuvx"};
    int w,x,y,z;
    string plaintext=args[1];
    string ciphertext="";
    if(plaintext.length()%2!=0)
    {
        plaintext+="x";
    }
    for(uint i=0;i<plaintext.length()-1;i+=2)
    {
        findposIn(mat,plaintext[i],w,x);
        findposIn(mat,plaintext[i+1],y,z);
        //debug(w);
        //debug(x);
        //debug(y);
        //debug(z);
        //horizontally same
        if(w==y)
        {
            ciphertext.push_back(mat[w][(x+1)%5]);
            ciphertext.push_back(mat[y][(z+1)%5]);
        }
        //vertically same
        else if(x==z)
        {
            ciphertext.push_back(mat[(w+1)%5][x]);
            ciphertext.push_back(mat[(y+1)%5][z]);
        }
        else
        {
            ciphertext.push_back(mat[y][x]);
            ciphertext.push_back(mat[w][z]);
        }
    }
    cout<<ciphertext<<endl;
    return 0;
}
