
#include <iostream>
using namespace std;


void add(int a, int b)
{
    cout<<"inside function pointer sum is : "<<a+b<<endl;
}

class subtract{
    public:
    void operator()(int b,int c)
    {
        cout<<"functor=class+operator overload:\n"<<b-c<<endl;
    }
};

int main() {
    subtract obj;
    obj(9,2);
    
    void (*ptr)(int,int)=add;
    ptr(6,7);
    
    auto comparison=[](int a,int b){ return a>b?a:b;};
    int result=comparison(9,3);
    cout<<"result of lambda is: "<<result;
    int i=8,j=9;

    auto it=[](){ return a>b?a:b;};
    int ans=it(6,7);

    capture =  [&] can capture all above values in code and overrite it
    capture =  [=] can capture all above values in code with read only
    return 0;
}