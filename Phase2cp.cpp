#include <iostream>
using namespace std;
void wait(int &z)
{
    z--;
}
void signal(int &z)
{
    z++;
}
void producer(int mutex, int &Empty, int full, int &x)
{
    wait(mutex);
    wait(Empty);
    signal(full);
    x++;
    cout << "producer produced item " << x << endl;
    cout << full << endl;
    cout << mutex;
   signal(mutex);
}
void consumer(int &mutex, int &Empty, int &full,int &x)
{
    wait(mutex);
    signal(Empty);
    wait(full);
    cout << "consumer consumed item " << x << endl;
    x--;
    signal(mutex);
}
int main()
{
    int full,n,x = 0;
    int Empty = 3;
    int h,mutex =1;
    while (h = 1)
    {
      cout << "1.Producer" << endl;
    cout << "2.Consumer" << endl;
    cout << "3.Exit" << endl;
    cout << "enter your choice: ";
    cin >> n;
    switch (n)
      {
        case 1: if ((mutex ==1)&& (Empty !=0))
        producer(mutex,Empty,full,x);
        else
            cout << "Buffer is full" << endl;
        break;
        case 2: if((mutex == 1)&& (full !=0))
        consumer(mutex,Empty,full,x);
        else
            cout << "Buffer is Empty" << endl;
        break;
        case 3:
            h = 0;
            break;
      }
        cout << endl;
    }

    return 0;
}
