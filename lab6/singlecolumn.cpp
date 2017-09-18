/*

*/
#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<" = "<<x<<endl
#define ll long long
using namespace std;

string columinar(string in)
{
    string out="",o[5]={""};
    int key[5]={2,3,1,4,0};
    for(int i=0;i<in.length();i++)
    {
        o[key[i%5]].push_back(in[i]);
    }
    out=o[0]+o[1]+o[2]+o[3]+o[4];
    return out;
}

int main(int argv,char *args[])
{
	//ios::sync_with_stdio(false);
    cout<<columinar(args[1])<<endl;
    return 0;
}
