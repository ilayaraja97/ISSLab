#include <bits/stdc++.h>
using namespace std;
#define A 14
#define B 26
#define C 17

int gcd(int a, int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int modPower(int x, int y, int n)
{
    int temp;
    if( y == 0)
       return 1;
    temp = modPower(x, y/2,n)%n;
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

string rsaDecrypt(string in)
{
	if(in.length()==0)
        return "";
    while(in.length()<8)
    {
        in.push_back(' ');
    }
	int64_t pt=in[0];
	pt=(pt<<8)|in[1];
	pt=(pt<<8)|in[2];
	pt=(pt<<8)|in[3];
	pt=(pt<<8)|in[4];
	pt=(pt<<8)|in[5];
	pt=(pt<<8)|in[6];
	pt=(pt<<8)|in[7];
	const int primes[]=
	{
		83,     89,     97,    101,    103,    107,    109,    113,
		127,    131,    137,    139,    149,    151,    157,    163,    167,    173,
		179,    181,    191,    193,    197,    199,    211,    223,    227,    229,
		233,    239,    241,    251,    257,    263,    269,    271,    277,    281,
		283,    293,    307,    311,    313,    317,    331,    337,    347,    349,
		353,    359,    367,    373,    379,    383,    389,    397,    401,    409,
		419,    421,    431,    433,    439,    443,    449,    457,    461,    463,
		467,    479,    487,    491,    499,    503,    509,    521,    523,    541,
		547,    557,    563,    569,    571,    577,    587,    593,    599,    601,
		607,    613,    617,    619,    631,    641,    643,    647,    653,    659,
		661,    673,    677,    683,    691,    701,    709,    719,    727,    733,
		739,    743,    751,    757,    761,    769,    773,    787,    797,    809,
		811,    821,    823,    827,    829,    839,    853,    857,    859,    863,
		877,    881,    883,    887,    907,    911,    919,    929,    937,    941,
		947,    953,    967,    971,    977,    983,    991,    997
    };
    int p=primes[A],q=primes[B];
    int n=p*q;
    int e=2;
    int f=(p-1)*(q-1);
    while(e<f)
    {
        if(gcd(e,f))
            break;
        else
            e++;
    }
    int d=(1+(C*f))/e;
    int64_t ct = modPower(pt,d,n);
    string out = "";
    for(int i=1;i<=8;i++)
    {
        out.push_back((ct>>(64-8*i))&0xFF);
    }
    return out+((in.length()>8)?rsaDecrypt(in.substr(8)):"");
}

string rsaEncrypt(string in)
{
	if(in.length()==0)
        return "";
    while(in.length()<8)
    {
        in.push_back(' ');
    }
	int64_t pt=in[0];
	pt=(pt<<8)|in[1];
	pt=(pt<<8)|in[2];
	pt=(pt<<8)|in[3];
	pt=(pt<<8)|in[4];
	pt=(pt<<8)|in[5];
	pt=(pt<<8)|in[6];
	pt=(pt<<8)|in[7];
	const int primes[]=
	{
		83,     89,     97,    101,    103,    107,    109,    113,
		127,    131,    137,    139,    149,    151,    157,    163,    167,    173,
		179,    181,    191,    193,    197,    199,    211,    223,    227,    229,
		233,    239,    241,    251,    257,    263,    269,    271,    277,    281,
		283,    293,    307,    311,    313,    317,    331,    337,    347,    349,
		353,    359,    367,    373,    379,    383,    389,    397,    401,    409,
		419,    421,    431,    433,    439,    443,    449,    457,    461,    463,
		467,    479,    487,    491,    499,    503,    509,    521,    523,    541,
		547,    557,    563,    569,    571,    577,    587,    593,    599,    601,
		607,    613,    617,    619,    631,    641,    643,    647,    653,    659,
		661,    673,    677,    683,    691,    701,    709,    719,    727,    733,
		739,    743,    751,    757,    761,    769,    773,    787,    797,    809,
		811,    821,    823,    827,    829,    839,    853,    857,    859,    863,
		877,    881,    883,    887,    907,    911,    919,    929,    937,    941,
		947,    953,    967,    971,    977,    983,    991,    997
    };
    int p=primes[A],q=primes[B];
    int n=p*q;
    int e=2;
    int f=(p-1)*(q-1);
    while(e<f)
    {
        if(gcd(e,f))
            break;
        else
            e++;
    }
    int d=(1+(C*f))/e;
    int64_t ct = modPower(pt,e,n);
    string out = "";
    for(int i=1;i<=8;i++)
    {
        out.push_back((ct>>(64-8*i))&0xFF);
    }
    return out+((in.length()>8)?rsaEncrypt(in.substr(8)):"");
}

int main(int argv,char *argc[])
{
	cout<<rsaEncrypt(argc[1])<<endl;
	return 0;
}
