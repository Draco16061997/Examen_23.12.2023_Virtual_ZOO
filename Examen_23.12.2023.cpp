//Разработка системы управления виртуальным зоопарком
#include <iostream>
#include<vector>

using namespace std;

// baise class Animall
class Animal{
private:
    string name;
    int healing = 100;
    int food = 100;
public:
    Animal(string name) {
        this->name = name;
        
    }

    string getName() { return name;}
    void setName(string name) { this->name = name; }

    int getHealing() { return healing; }

    void addHealing(int healing) {
        if (getHealing() > 0) {
            if (getHealing() + healing >= 100) {
                this->healing = 100;
            }
            else if (getHealing() + healing < 100 and getHealing() + healing >= 0) {
                this->healing += healing;
            }
            else { this->healing = 0; }
        }
        else
        {
            cout << "Animal " << getName() << " is DEAD!" << endl;
            
        }

       

    }

    int getFood() { return food; }

    void addFood(int food) {
        if (getHealing() > 0) {
            if (getFood() + food >= 100) {
                this->food = 100;
            }
            else if (getFood() + food < 100 and getFood() + food >= 0) {
                this->food += food;
            }
            else { this->food = 0; }
        }
        else
        {
            cout << "Animal " << getName() << " is DEAD! Is NOT HUNGRY!!((" << endl;

        }
        
    }



};
    


class Emploue {
private:
    string name;
    int age;

public:
    Emploue(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    int getAge() { return age; }

    void setAge(int age) { this->age = age; }
};




void main()
{
    /*Animal cat("jony");

    cout <<cat.getName()<< endl;
    cout<<cat.getHealing()<<endl;
    cat.addHealing(-50);
    cout << cat.getHealing() << endl;
    cat.addHealing(20);
    cout << cat.getHealing() << endl;
    cat.addHealing(-710);

    cout << cat.getHealing() << endl;
    cat.addHealing(2);
    cout << cat.getHealing() << endl;

    cout << "FOOD "<< cat.getFood() << endl;

    cat.addFood(20);
    cout << "FOOD " << cat.getFood() << endl;

    cat.addFood(-40);
    cout << "FOOD " << cat.getFood() << endl;
    cat.addFood(-60);
    cout << "FOOD " << cat.getFood() << endl;*/


}

