#include <iostream>
using namespace std;

#define PI 3.14159465
#define MAXX(x, y) (x > y ? x : y)
float circleArea(float r)
{
    return PI * r * r;
}

float circlePerimeter(float r)
{
    return 2 * PI * r;
}
void fun1()
{
    int x = 6;
    int b = 17;
    int c = MAXX(x, b);
//above and below line is same in functioning
    // int c = x > b ? x : b;
}
void fun2()
{
    int a = 6;
    int b = 17;
    int c = MAXX(a, b);
}
void fun3()
{
    int x = 6;
    int y = 17;
    int c = MAXX(x, y);
}
int main()
{
    cout << circleArea(65.4) << endl;
}