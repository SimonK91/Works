#include <iostream>
#include <vector>
#include <chrono>
#include <string>

#include "heap_sort.cpp"


class person
{
public:
    person(int age,std::string name)
    {
	this->age = age;
	this->name = name;
    }
    int age;
    std::string name;
};

std::ostream& operator<<(std::ostream& os, const person& p)
{
    os << "name: " << p.name << std::endl
       << " age: " << p.age;
    return os;
}

bool sortByAge(person lhs, person rhs){ return lhs.age < rhs.age; }
bool sortByName(person lhs, person rhs){ return lhs.name < rhs.name; }

using namespace std;
using namespace chrono;
int main()
{
    vector<person> v1;
    v1.push_back(person(11,"a"));
    v1.push_back(person(10,"b"));
    v1.push_back(person(9,"c"));
    v1.push_back(person(8,"d"));
    v1.push_back(person(7,"e"));
    auto start = high_resolution_clock::now();
    
    cout << "unsorted list: " << endl;
    for(auto it : v1)
    {
	cout << it << endl;
    }

    heap_sort(v1,sortByAge);
     cout << "\nsorted by age: " << endl;
    for(auto it : v1)
    {
    	cout << it << endl;
    }

    heap_sort(v1,sortByName);
    cout << "\nsorted by name: " << endl;
    for(auto it : v1)
    {
    	cout << it << endl;
    }

    return 0;
}
