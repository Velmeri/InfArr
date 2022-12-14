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
	T GetAt(int i) const;

	void SetCapacity(int s);
	void SetGrow(int s); // a function should only perform one specific task. I see no reason to combine this with SetSize()
	void SetArr(T* begin, T* end);
	void SetAt(int i, T value);

	T& operator[] (int i);
	T& operator= (infarr& obj);

	bool IsEmpty() const;
	void FreeExtra();
	void RemoveAll();
	void Append(infarr obj);
	void Append(T* begin, T* end);
	T* GetData();
	void InsertAt(T value);
	void RemoveAt();
};

int main() {
	int arr[] = {1, 2, 3 ,4, 5};
	int arrr[] = { 6, 7, 8, 9, 10, 11, 12, 13 };

	infarr<int> arr1;
	infarr<int> arr2(begin(arr), end(arr));
	arr1.SetArr(begin(arr), end(arr));
	cout << arr1.GetCapacity() << endl;
	arr1.FreeExtra();
	cout << arr1.GetCapacity() << endl;
	cout << arr1.GetSize() << endl;
	arr1[0] = 6;
	arr1.Append(begin(arrr), end(arrr));
	arr1.InsertAt(111);
	arr1.InsertAt(222);
	arr1.RemoveAt();
	cout << "\n\t";
	for (int i = 0; i < arr1.GetSize(); i++)
		cout << arr1[i] << ' ';
	cout << "\n\t\t" << arr1.GetData() << endl;

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
	size = 0;
	for (T* ptr = begin; ptr != end; ptr++)
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
	for (T* ptr = begin; ptr != end; ptr++)
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
		T* TempArr = new T[capacity];
		for (int i = 0; i < size; i++)
			TempArr[i] = arr[i];
		arr = TempArr;
		delete TempArr;
	}
}

template<class T>
void infarr<T>::SetGrow(int s)
{
	if (s < 0) {
		//I don't know much about the windows.h
		HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE); //But from what I understand this function extracts a link to the program (here on the console)
		SetConsoleTextAttribute(window, 4); //And this function changes what will be displayed in window (more accurate, it change color of output)
		cout << "\n\tError - wrong size\n";
		SetConsoleTextAttribute(window, 15);
		//Maybe I misunderstood something, but the main thing is that it works as I want
	}
	else
		grow = s;
}

template<class T>
void infarr<T>::SetArr(T* begin, T* end)
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
void infarr<T>::SetAt(int i, T value)
{
	if (i < 0 || i > size) {
		HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(window, 4);
		cout << "\n\tError - wrong index\n";
		SetConsoleTextAttribute(window, 15);
	}
	else
		arr[i] = value;
}

template<class T>
T infarr<T>::GetAt(int i) const
{
	if (i < 0 || i > size) {
		HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(window, 4);
		cout << "\n\tError - wrong index\n";
		SetConsoleTextAttribute(window, 15);
	}
	else
		return arr[i];
}

template<class T>
T& infarr<T>::operator[](int i)
{
	return arr[i];
}

template<class T>
T& infarr<T>::operator=(infarr& obj)
{
	if (arr != nullptr)
		delete[] arr;
	capacity = obj.capacity;
	size = obj.size;
	arr = new T[capacity];
		for (int i = 0; i < size; i++)
			arr[i] = obj.arr[i];

	return *this;
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

template<class T>
void infarr<T>::RemoveAll()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<class T>
void infarr<T>::Append(infarr obj)
{
	T* TempArr = new T[size];
	int OldSize = size;
	for (int i = 0; i < size; i++)
		TempArr[i] = arr[i];
	if (arr != nullptr)
		delete[] arr;
	size += obj.size;
	while (capacity < size) {
		if (grow == 0)
			for (capacity = 1; capacity < size; capacity *= 2);
		else
			capacity += grow;
	}
	arr = new T[capacity];
	for (int i = 0; i < OldSize; i++)
		arr[i] = TempArr[i];
	for (int i = size - OldSize; i < size; i++)
		arr[i] = obj.arr[i - OldSize];
}

template<class T>
void infarr<T>::Append(T* begin, T* end)
{
	int ObjSize = 0;
	for (T* ptr = begin; ptr != end; ptr++)
		ObjSize++;
	T* TempArr = new T[size];
	int OldSize = size;
	for (int i = 0; i < size; i++)
		TempArr[i] = arr[i];
	if (arr != nullptr)
		delete[] arr;
	size += ObjSize;
	while (capacity < size) {
		if (grow == 0)
			for (capacity = 1; capacity < size; capacity *= 2);
		else
			capacity += grow;
	}
	arr = new T[capacity];
	for (int i = 0; i < OldSize; i++)
		arr[i] = TempArr[i];
	delete[]TempArr;
	cout << OldSize;
	for (int i = OldSize; i < size; i++)
		arr[i] = *(begin + i - OldSize);
}

template<class T>
T* infarr<T>::GetData()
{
	return &arr[0];
}

template<class T>
void infarr<T>::InsertAt(T value)
{
	size += 1;
	while (capacity < size) {
		if (grow == 0)
			for (capacity = 1; capacity < size; capacity *= 2);
		else
			capacity += grow;
	}
	T* TempArr = new T[capacity];
	for (int i = 0; i < size - 1; i++)
		TempArr[i] = arr[i];
	TempArr[size - 1] = value;
	delete[] arr;
	arr = TempArr;
}

template<class T>
void infarr<T>::RemoveAt()
{
	size--;
	arr[size] = 0;
}
