#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int e,f;
	cin>>e;
	cin>>f;
	int a[e];
	int b[f];
	for(int i=0;i<e;i++)
	{
		cin>>a[i];
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	for(int j=0;j<f;j++)
	{
		cin>>b[j];
		cout<<b[j]<<"\t";
	}
	cout<<endl;
	vector<int>c;
    int l=0;
    for(int i=1;i<=b[0];i++)
    {
        int k=1;
        cout<<i<<endl;
        for(int j=0;j<e;j++)
        {
        	cout<<j<<"\t";
            if(i%a[j]==0)
            {
                k=k+1;
                cout<<k<<endl;
            }
            else{
            	continue;
			}
        }
        if(k==e)
        {
            c[l]=i;
            cout<<i<<endl;
            l=l+1;
        }
    }
    int g=0;
    for(int i=0;i<c.size();i++)
    {
        int m=1;
        for(int j=0;j<f;j++)
        {
            if(b[j]%c[i]==0)
            {
                m=m+1;
            }
        }
        if(m==f)
        {
            g=g+1;
        }
    }
    cout<<g;
    return 0;
}
