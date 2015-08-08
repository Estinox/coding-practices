#include <iostream>

using namespace std;

// Template Function
template <typename T>
class Array
{
private:
  T* ptr;
  int size;
  int id;
public:
  Array(T arr[], int n, int id=0);
  void print();

  Array<T>& operator=(const Array<T> that);
  Array(const Array<T>& that);
  ~Array();
};

template <typename T>
Array<T>::Array(T arr[], int s, int i)
{
  ptr = new T[s];
  size = s;
  id = i;
  for (int i = 0; i < s; i++)
    ptr[i] = arr[i];

  cout << "Constructed " << id << endl;
}

template <typename T>
void Array<T>::print()
{
  cout << "ID: " << id << " - ";
  for (int i = 0; i < size; i++)
    cout << ptr[i] << " ";

  cout << endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> that)
{
  // Apply the copy and swap idiom
  swap(*this, that);
  ++id;

  cout << "Assigned" << id << endl;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array<T>& that)
{
  ptr = new T[that.size];
  size = that.size;
  ++id;
  for (int i = 0; i < size; i++)
    ptr[i] = that.ptr[i];

  cout << "Copied " << id << endl;
}

template <typename T>
Array<T>::~Array()
{
  if (ptr)
  {
    delete ptr;
    cout << "Deleted " << id << endl;
  }
}


int main()
{
  int l[] = {1, 2, 3, 4, 5};
  Array<int>* a = new Array<int>(l, 5, 0);
  Array<int> b(*a);

  return 0;
}


