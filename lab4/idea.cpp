#include <bits/stdc++.h>
using namespace std;

void keygen(int key[128],int &index,int res[16])
{
	for(int i=0;i<16;i++) res[i]=0;
	if(index>=127)
	{
		int temp[25];
		for(int i=0;i<25;i++)
		{
			temp[i]=key[i];
		}
		for(int i=25;i<128;i++)
		{
			key[i-25]=key[i];
		}
		for(int i=0;i<25;i++)
		{
			key[127-25+i]=temp[i];
		}
		index=0;
	}
	for(int i=index;index<128&&index-i<16;index++)
	{
		res[index-i]=key[index];
	}
}

int main(int argv,char *argc[])
{
	 in=argc[1],keyS="00010011001101000101011101111001100110111011110011011111111100010001001100110100010101110111100110011011101111001101111111110001";
	int input[64]={0},
		key[128]={0};
	for(int i=0;i<64;i++)
    {
        input[i]=in[i]-'0';
    }
    for(int i=0;i<128;i++)
    {
        key[i]=keyS[i]-'0';
    }
    int index=0;
    int k1[16];
    for(int j=0;j<16;j++){
    keygen(key,index,k1);
    for(int i=0;i<16;i++)
    {
        cout<<k1[i]<<" ";
    }cout<<endl;
    }
	return 0;
}
