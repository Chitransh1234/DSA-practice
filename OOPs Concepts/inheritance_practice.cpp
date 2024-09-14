#include <iostream>
#include <string>
#include <vector>

using namespace std;
// parent class;
class Bird
{
public:
    int age, weight;
    int nol;
    string color;

    void eat()
    {
        cout << "Bird is eating" << endl;
    }
    void fly()
    {
        cout << "Bird is flying" << endl;
    }
};

class Sparrow : public Bird
{
public:
    // ctor
    Sparrow(int age, int weight, string color, int nol)
    {
        this->age = age;
        this->weight = weight;
        this->color = color;
        this->nol = nol;
    }
    void grassing()
    {
        cout << "Sparrow is grassing." << endl;
    }
    int getnol(){
        return this->nol;
    }
};
class Peigon : public Bird
{
public:
    void guttering()
    {
        cout << "Peigon is guttering." << endl;
    }
};
class parrot : public Bird
{
public:
    void speaking()
    {
        cout << "parrot is speaking." << endl;
    }
}; 
int main()
{
    Sparrow s(1, 1, "brown", 2);
    cout << s.color << endl;
    cout << s.weight << "kg" << endl;
    s.eat();
    s.grassing();

    Peigon p;
    p.eat();
    p.guttering();
    return 0;
}