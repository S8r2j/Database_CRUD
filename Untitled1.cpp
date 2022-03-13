#include<vector>
#include <string>
#include <iostream>

using namespace std;


/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(vector<int> a, vector<int> b) {
    vector<int> c;
    int l=0;
    for(int i=1;i<=b[0];i++)
    {
        int k=1;
        for(int j=0;j<a.size();j++)
        {
            if(i%a[j]==0)
            {
                k=k+1;
            }
        }
        if(k==a.size())
        {
            c[l]=i;
            l=l+1;
        }
    }
    int g=0;
    for(int i=0;i<c.size();i++)
    {
        int m=1;
        for(int j=0;j<b.size();j++)
        {
            if(b[j]%c[i]==0)
            {
                m=m+1;
            }
        }
        if(m==b.size())
        {
            g=g+1;
        }
    }
    return g;
}

int main()
{
    vector<int>a;
    vector<int>b;
    int c,d;
    cin>>c;
    cin>>d;
    int i,j;
    for(i=0;i<c;i++)
    {
    	cin>>a[i];
	}
	for(j=0;j<d;j++)
	{
		cin>>b[j];
	}
	int k=getTotalX(a,b);
	cout<<k;
	return 0;
}

