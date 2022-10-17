#include <iostream>
#include <windows.h>

using namespace std;

template <class T>
class infarr
{
	int capacity;
	int size;
	int grow;
	T* arr;
public:
	infarr();
	infarr(T* begin, T* end);
	~infarr();

	int GetSize() const; // it's the same that is GetUpperBound
	int GetCapacity() const;

	void SetCapacity(int s);
	void SetGrow(int s); // a function should only perform one specific task. I see no reason to combine this with SetSize()
	T operator[] (int i);

	bool IsEmpty() const;
	void FreeExtra();

};

int main() {
	int arr[] = {1, 2, 3 ,4, 5};

	infarr<int> arr1(begin(arr), end(arr));
	arr1.FreeExtra();
	cout << arr1.GetCapacity() << endl;
	cout << arr1.GetSize() << endl;

	for (int i = 0; i < arr1.GetSize(); i++)
		cout << arr1[i] << ' ';

	return 0;
}

template<class T>
infarr<T>::infarr()
{
	size = 0;
	capacity = 0;
	grow = 0;
	arr = nullptr;
}

template<class T>
infarr<T>::infarr(T* begin, T* end)
{
	if (arr != nullptr)
		delete[] arr;
	size = 0;
	for (int* ptr = begin; ptr != end; ptr++)
	{
		++size;
	}
	while (capacity < size) {
		if (grow == 0)
			for (capacity = 1; capacity < size; capacity *= 2);
		else
			capacity += grow;
	}
	arr = new T[capacity];
	int i = 0;
	for (int* ptr = begin; ptr != end; ptr++)
		arr[i++] = *ptr;
}

template<class T>
infarr<T>::~infarr()
{
	delete[] arr;
}

template<class T>
int infarr<T>::GetSize() const
{
	return size;
}

template<class T>
int infarr<T>::GetCapacity() const
{
	return capacity;
}

template<class T>
void infarr<T>::SetCapacity(int s)
{
	if (s < 0) {
		//I don't know much about the windows.h
		HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE); //But from what I understand this function extracts a link to the program (here on the console)
		SetConsoleTextAttribute(window, 4); //And this function changes what will be displayed in window (more accurate, it change color of output)
		cout << "\n\tError - wrong size. Number cannot be less than 0\n";
		SetConsoleTextAttribute(window, 15);
		//Maybe I misunderstood something, but the main thing is that it works as I want
	}

	else if (s < size) {
		//I don't know much about the windows.h
		HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE); //But from what I understand this function extracts a link to the program (here on the console)
		SetConsoleTextAttribute(window, 4); //And this function changes what will be displayed in window (more accurate, it change color of output)
		cout << "\n\tError - wrong size. You must delete elements before it\n";
		SetConsoleTextAttribute(window, 15);
		//Maybe I misunderstood something, but the main thing is that it works as I want
	}
	else {
		capacity = s;
	}
}

template<class T>
void infarr<T>::SetGrow(int s)
{
	//I don't know much about the windows.h
	HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE); //But from what I understand this function extracts a link to the program (here on the console)
	SetConsoleTextAttribute(window, 4); //And this function changes what will be displayed in window (more accurate, it change color of output)
	cout << "\n\tError - wrong size\n";
	SetConsoleTextAttribute(window, 15);
	//Maybe I misunderstood something, but the main thing is that it works as I want
}

template<class T>
T infarr<T>::operator[](int i)
{
	return arr[i];
}

template<class T>
bool infarr<T>::IsEmpty() const
{
	if (size == 0)
		return 1;
	return 0;
}

template<class T>
void infarr<T>::FreeExtra()
{
	T* TempArr = new T[size];
	for (int i = 0; i < size; i++)
		TempArr[i] = arr[i];
	delete[] arr;
	arr = TempArr;
	capacity = size;
}
