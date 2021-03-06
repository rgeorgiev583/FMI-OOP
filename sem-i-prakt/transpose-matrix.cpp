#include <iostream>
using namespace std;

void writeMatrix(int** a,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void transposeMatrix()
{
    int n,m;
    cin>>n>>m;
    int** a=new int*[m];
    for(int i=0;i<m;i++)
        a[i]=new int[n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    int** b=new int*[n];
    for(int i=0;i<n;i++)
        b[i]=new int[m];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            b[j][i]=a[i][j];
    writeMatrix(b,n,m);
    for(int i=0;i<n;i++)
        delete[] b[i];
    for(int i=0;i<m;i++)
        delete[] a[i];
    delete[] b;
    delete[] a;
}

int main()
{
    transposeMatrix();

	return 0;
}
