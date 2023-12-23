//Разработка системы управления виртуальным зоопарком
#include <iostream>
#include<vector>
#include<cctype>
#include<string>
using namespace std;

// baise class Animall
class Animal{
private:
    string name;
    int healing = 100;
    int food = 100;
    int age;
    string sex;
public:
    Animal(string name, int age, string sex) {
        this->name = name;
        this->age = age;
        if (sex == "he" or sex == "she") { this->sex = sex; }
        else
        {
            throw exception("sex is not diferend!");

        }
        
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

    int getAge() { return age; }

    void addAge(int Age) {
        if (Age > 0) {
            if (0 > this->age + Age < 100) {
                this->age += Age;
            }
            else
            {
                cout << "AGE OWER 100 YEAR" << endl;
            }
        }
        else
        {
            cout << "invalid AGE!!!" << endl;
        }
    }

    string getSex() { return sex; }

    void Sex(string sex) {

        if (sex == "he" or sex == "she") { this->sex = sex; }
        else
        {
            throw exception("sex is not diferend!");

        }
    }

    void getAnimalInfo() {
        string HP;

        if (getHealing() == 0) { HP = "is DEATH!"; }
        else
        {
            HP = to_string(getHealing());
        }

        cout << "NAME: " <<getName() << endl
            << "AGE: " << getAge() <<" Year!" << endl
            << "its: " << getSex() << endl
            << "HP: " << HP << endl
            << "FOOD: " <<getFood() << endl << endl;
    }
};
    
//Базовый клас роботник 

class Emploue {
private:
    string name;
    int age;
    string sex;

public:
    Emploue(string name, int age) {
        this->name = name;
        this->age = age;
        if (sex == "man" or sex == "woman") { this->sex = sex; }
        else
        {
            throw exception("is sex ont diferend! ");

        }
    }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    int getAge() { return age; }

    void setAge(int age) { this->age = age; }

    string getSex() { return sex; }

    void getSex(string sex) {

        if (sex == "man" or sex == "woman") { this->sex = sex; }
        else
        {
            throw exception("is sex ont diferend! ");

        }
    }
};


//клас вольер 
class Enclouse {
private:
    int size;
    vector<Animal> Animals;

public:

    Enclouse(int size) { this->size = size; }

    void getInfoEnclouse() {
        for (int i = 0; i < Animals.size(); i++) {
            cout << "it " << i << endl;
            Animals[i].getAnimalInfo();
            cout << endl << endl;
        }
    }

    void AddAnimal(Animal animal) {
        if (size > Animals.size()) {
            Animals.push_back(animal);
            cout << "Animal its ADD to ENCLOUSE!" << endl;
        }
        else { throw exception("Enclouse is maximum!"); }
    }

    void RemoveAnimal(int it) {
        cout << "Animal its DELETED! " << endl;
        Animals[it].getAnimalInfo();
        Animals.erase(Animals.begin() + it);
    }
};




void main()
{

    try
    {
        Animal cat("Murzik", 3, "she");
        Animal dog("Smurf", 4, "he");
        Animal chiken("Coco", 6, "he");




        Enclouse cage(2);

        cage.AddAnimal(cat);

        cage.AddAnimal(dog);

        cage.AddAnimal(chiken);

        cage.getInfoEnclouse();

        
        

    }
    catch (const std::exception& err)
    {
        cout << err.what() << endl;
    }
    
    

}
 
