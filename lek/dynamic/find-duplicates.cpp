#include <iostream>
using namespace std;

double* resize(double* a,int& capacity)
{
    int newcapacity=capacity*2;
    double* newa=new double[newcapacity];
    for(int i=0;i<capacity;i++)
        newa[i]=a[i];
    delete[] a;
    capacity=newcapacity;
    return newa;
}

void findDuplicates()
{
    int capacity=10,count=0;
    double* a=new double[capacity];
    double x;
    do
    {
        cin>>x;
        a[count++]=x;
        if(count==capacity)
            a=resize(a,capacity);
    }
    while(x!=0);
    int i=0,j=count;
    while(i<count-1&&j==count)
    {
        j=i+1;
        while(j<count&&a[i]!=a[j])
            j++;
        i++;
    }
    cout<<"There "<<(j<count?"is at least one repetition.":"are no repetitions.")<<endl;
}

int main()
{
    findDuplicates();

	return 0;
}
