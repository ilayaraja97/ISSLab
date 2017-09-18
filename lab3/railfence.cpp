#include <bits/stdc++.h>
using namespace std;

string railFence(string in, int k)
{
    char rail[k][(in.length())]={0};
 
    bool isDown = false;
    int r = 0, c = 0;
 
    for (uint i=0; i < in.length(); i++)
    {
        if (r == 0 || r == k-1)
            isDown = !isDown;
        rail[r][c++] = in[i];
        if(isDown)
            r++;
        else
            r--;
    }
    string res;
    for (int i=0; i < k; i++)
        for (uint j=0; j < in.length(); j++)
            if (rail[i][j]!='\n')
                res.push_back(rail[i][j]);
 
    return res;
}

int main(int argv,char *args[])
{
    cout<<railFence(args[1],atoi(args[2]))<<endl;
    return 0;
}
  
