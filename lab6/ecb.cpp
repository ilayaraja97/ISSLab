/*
demonstration of ecb type cipher
*/
#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<" = "<<x<<endl
#define ll long long
using namespace std;

string xor_ecb(string in)
{
    if(in.length()==0)
        return "";
    while(in.length()<8)
    {
        in.push_back(' ');
    }
	uint64_t pt=in[0];
	pt=(pt<<8)|in[1];
	pt=(pt<<8)|in[2];
	pt=(pt<<8)|in[3];
	pt=(pt<<8)|in[4];
	pt=(pt<<8)|in[5];
	pt=(pt<<8)|in[6];
	pt=(pt<<8)|in[7];
	uint64_t key = 1432673451324325234L;
    uint64_t ct = pt^key;
    string out = "";
    for(int i=1;i<=8;i++)
    {
        out.push_back((ct>>(64-8*i))&0xFF);
    }
    return out+((in.length()>8)?xor_ecb(in.substr(8)):"");
}

int main(int argv,char *args[])
{
	//ios::sync_with_stdio(false);
    cout<<xor_ecb("raja")<<endl;
    return 0;
}
