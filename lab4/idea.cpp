#include <bits/stdc++.h>
#define int64 int64_t
#define int128 __int128_t
using namespace std;

int16_t keygen(int128 key,int index)
{
    int16_t res=0;
    for(int i=0;i<index/8;i++)
    {
        int128 a = key,mask25 = 33554432L;
        //mask25=mask25<<(128-25);
        
        a = (key>>(128-25))&mask25;
        
        key=(key<<25)|a;
    }
    
    int128 mask16 = 0xFFFF;
    res=(key>>(128-16*(index%8)))&mask16;
    return res;
}

string ideaEcrypt(string in)
{
    if(in.length()==0)
        return "";
    while(in.length()<8)
    {
        in.push_back(' ');
    }
    
    //key stored in int128 so to init key we need 2 steps
    int64 keyPart1 = 2342157647623545L,keyPart2 = 1234566543726758975L;
    int128 key = 0x0|keyPart1;
    key = (key<<64)|keyPart2;
    //cout<<(int64)(i>>64)<<setfill('0')<<setw(19)<<int64(i)<<endl;
    
    int64 mask16=0xFFFF,mask8=0xFF;
    int64 pt = 0x0|in[0];
    pt = (pt<<8)|in[1];
    pt = (pt<<8)|in[2];
    pt = (pt<<8)|in[3];
    pt = (pt<<8)|in[4];
    pt = (pt<<8)|in[5];
    pt = (pt<<8)|in[6];
    pt = (pt<<8)|in[7];
    
    int index=0;
    int16_t p1 = (pt>>(64-16))&mask16,
        p2 = (pt>>(64-16*2))&mask16,
        p3 = (pt>>(64-16*3))&mask16,
        p4 = (pt>>(64-16*4))&mask16;
    
    for(int i=0;i<8;i++)
    {
        int16_t s1,s2,s3,s4,s5,s6,s7,s8,s9,s0;
        s1 = (p1 * keygen(key,index++))%(0xFFFF);
        s2 = (p2 + keygen(key,index++))%(0xFFFF);
        s3 = (p3 + keygen(key,index++))%(0xFFFF);
        s4 = (p4 * keygen(key,index++))%(0xFFFF);
        s5 = s1 ^ s3;
        s6 = s2 ^ s4;
        s7 = (s5 * keygen(key,index++))%(0xFFFF);
        s8 = s6 + s7;
        s9 = (s8 * keygen(key,index++))%(0xFFFF);
        s0 = s7 + s9;
        p1 = s1 ^ s9;
        p2 = s3 ^ s9;
        p3 = s2 ^ s0;
        p4 = s4 ^ s0;        
    }
    int16_t c1 = (p1 * keygen(key,index++))%(0xFFFF),
        c2 = (p2 + keygen(key,index++))%(0xFFFF),
        c3 = (p3 + keygen(key,index++))%(0xFFFF),
        c4 = (p4 * keygen(key,index++))%(0xFFFF);
    int64 ct = c1;
    ct = (ct<<16)|c2;
    ct = (ct<<16)|c3;
    ct = (ct<<16)|c4;
    
    string o = "";
    for(int i=1;i<=8;i++)
    {
        o.push_back((ct>>(64-8*i))&mask8);
    }
    return o+((in.length()>8)?ideaEcrypt(in.substr(8)):"");
}

int main(int argv,char *argc[])
{
    cout<<ideaEcrypt(argc[1])<<endl;
    return 0;
}
