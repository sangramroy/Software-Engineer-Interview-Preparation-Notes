
My __VERSION__

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class vector{
   int *ptr;
   int size;
   int capacity;
  
  public:
  
  vector()
  {
      size=0;
      capacity=0;
      ptr=new int;
      *ptr=0;
  }
  
    vector(int siz)
  {
      size=0;
      capacity=siz;
      ptr=new int[size];
  }
  
    void push(int data)
  {
     // cout<<"inside push function:\n";
      if(size==0 || size==capacity)
      {
          if(size==capacity)
          {
              capacity=2*capacity;
              cout<<"\nnow vector capacity is full so doubling its capacity: to "<<capacity<<endl;
          }
      }
     
          
          ptr[size]=data;
          cout<<"\ndata pushed in vector: "<<ptr[size]<<endl;
          size++;
          sizencap();
          cout<<endl;
  }
  
  void sizencap()
  {
       cout<<"size of vector is: "<<size<<endl;
      cout<<"capacity of vector is: "<<capacity;;
  }
  
    int getcapacity()
  {
      return capacity;
  }
  
  void pop()
  {
      cout<<"\ndata deleted from vector: "<<ptr[size]<<endl;
      size--;
      sizencap();
      cout<<endl;
  }
  
  void resize()
  {
      capacity=size;
      cout<<"vector is now resized to: "<<capacity<<endl;
  }
    
    int getsize()
    {
        return size;
    }
    
    int operator[](int size)
    {
       return *(ptr+size);
    }
};

int main(void)
{
  vector v(5);
  v.push(78);
  v.push(8);
  v.push(7);  
  v.push(43);
  v.push(76);
  v.push(16);
  v.pop();
  v.resize();
  cout<<"\niterating vector:\n";
  for(int i=0;i<=v.getsize();i++)
  {
      cout<<v[i]<<" ";
  }
  //cout << sizeof(derived);  //80

  return 0;

}



---------------------------------------------FIXED COREECTED CODE----------------------------------------------
#include <iostream>
using namespace std;

class Vector {
    int* ptr;
    int size;
    int capacity;

public:
    // Default constructor
    Vector() {
        ptr = nullptr;
        size = 0;
        capacity = 0;
    }

    // Parameterized constructor
    Vector(int cap) {
        size = 0;
        capacity = cap;
        ptr = new int[capacity];
    }

    // Destructor
    ~Vector() {
        delete[] ptr;
    }

    // Push an element to the end
    void push(int data) {
        if (size == capacity) {
            int newCap = (capacity == 0) ? 1 : 2 * capacity;
            int* newPtr = new int[newCap];

            for (int i = 0; i < size; i++) {
                newPtr[i] = ptr[i];
            }

            delete[] ptr;
            ptr = newPtr;
            capacity = newCap;

            cout << "Vector capacity increased to: " << capacity << endl;
        }

        ptr[size] = data;
        size++;
        cout << "Pushed: " << data << endl;
    }

    // Pop the last element
    void pop() {
        if (size > 0) {
            cout << "Popped: " << ptr[size - 1] << endl;
            size--;
        } else {
            cout << "Vector is empty!\n";
        }
    }

    // Resize the capacity to match the current size
    void resize() {
        int* newPtr = new int[size];
        for (int i = 0; i < size; i++) {
            newPtr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newPtr;
        capacity = size;
        cout << "Vector resized to capacity: " << capacity << endl;
    }

    // Get current size
    int getsize() {
        return size;
    }

    // Get current capacity
    int getcapacity() {
        return capacity;
    }

    // Access by index
    int operator[](int index) {
        if (index >= 0 && index < size) {
            return ptr[index];
        } else {
            cout << "Index out of bounds!" << endl;
            return -1;
        }
    }

    // Display size and capacity
    void sizencap() {
        cout << "Size: " << size << ", Capacity: " << capacity << endl;
    }
};

int main() {
    Vector v(2);

    v.push(78);
    v.push(8);
    v.push(7);
    v.push(43);
    v.push(76);
    v.push(16);
    v.pop();
    v.resize();

    cout << "\nIterating vector:\n";
    for (int i = 0; i < v.getsize(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
