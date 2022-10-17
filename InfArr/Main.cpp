#include <iostream>

using namespace std;

template <class T>
class infarr
{
	int capacity;
	int size;
	T* arr;
public:
	infarr();

	int GetSize();
	int GetCapacity();
};

int main() {
	infarr<int> arr1;
	cout << arr1.GetCapacity();
	cout << arr1.GetSize();

	return 0;
}

template<class T>
infarr<T>::infarr()
{
	size = 0;
	capacity = 0;
	arr = nullptr;
}

template<class T>
int infarr<T>::GetSize()
{
	return size;
}

template<class T>
int infarr<T>::GetCapacity()
{
	return capacity;
}
