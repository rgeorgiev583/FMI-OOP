#include <iostream>
#include "dynarray.cpp"
using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
	DynamicArray<int> da(a, 5);
	DynamicArray<int> da1(da);
	DynamicArray<int> da2 = da1;
	DynamicArray<int> da3;
	da3 = da2;
	DynamicArray<int> da4 = DynamicArray<int>(10);
	da4 = DynamicArray<int>(da3);

	for(size_t i = 0; i < 5; i++)
        cout << da4[i] << endl;

    cout << endl;
    cout << da4.front() << endl;
    cout << da4.back() << endl;
    da4.push_back(12);
    cout << da4.back() << endl;
    cout << da4.pop_back() << endl;
    cout << da4.back() << endl;
    cout << da4.size() << endl;
    cout << da4.empty() << endl;

	return 0;
}
