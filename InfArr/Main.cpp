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

	int GetSize();
	int GetCapacity();

	void SetSize(int s);
	void SetGrow(int s); // a function should only perform one specific task. I see no reason to combine this with SetSize()
};

int main() {
	infarr<int> arr1;
	cout << arr1.GetCapacity();

	arr1.SetSize(10);
	cout << arr1.GetSize();

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
int infarr<T>::GetSize()
{
	return size;
}

template<class T>
int infarr<T>::GetCapacity()
{
	return capacity;
}

template<class T>
void infarr<T>::SetSize(int s)
{
	if (s >= 0)
		size = s;
	else {
		//I didn't know much about the windows.h
		HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE); //But from what I understand this function extracts a link to the program (here on the console)
		SetConsoleTextAttribute(window, 4); //And this function changes what will be displayed in window (more accurate, it change color of output)
		cout << "\n\tError - wrong size\n";
		SetConsoleTextAttribute(window, 15);
		//Maybe I misunderstood something, but the main thing is that it works as I want
	}
}

template<class T>
void infarr<T>::SetGrow(int s)
{
	//I didn't know much about the windows.h
	HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE); //But from what I understand this function extracts a link to the program (here on the console)
	SetConsoleTextAttribute(window, 4); //And this function changes what will be displayed in window (more accurate, it change color of output)
	cout << "\n\tError - wrong size\n";
	SetConsoleTextAttribute(window, 15);
	//Maybe I misunderstood something, but the main thing is that it works as I want
}
