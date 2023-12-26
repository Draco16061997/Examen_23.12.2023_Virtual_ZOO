//Разработка системы управления виртуальным зоопарком
#include <iostream>
#include<vector>
#include<cctype>
#include<string>
#include<algorithm>


using namespace std;

int temp = 40;
int skyNowIt = 1;


void setSky(string sky) {
    if (sky == "sunny") { skyNowIt = 1; }
    else if (sky == "cloudly") { skyNowIt = 2; }
    else if ((sky == "rain" or sky == "snow") and temp > 0) { skyNowIt = 3; }
    else if ((sky == "rain" or sky == "snow") and temp <= 0) { skyNowIt = 4; }
    else { throw exception("invalid select SKY enter is atribute: sunny, rain, snow, cloudly and using low symbol!!!"); }
}


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
            throw exception("sex is not diferend! using is lowcase 'he' or 'she' ");

        }
        
    }

    string getName() { return name;}
    void setName(string name) { this->name = name; }

    int getHealing() { return healing; }

    void addHealing(int healing) {
        if (getHealing() > 0) {

            this->healing += healing;

            /*this->healing = this->healing > 100 ? 100 : this->healing;
            this->healing = this->healing < 0 ? 0 : this->healing;*/

            if (this->healing > 100) {
                this->healing = 100;
            }

            if (this->healing < 0) {
                this->healing = 0;
            }

          /*  if (getHealing() + healing >= 100) {
                this->healing = 100;
            }
            else if (getHealing() + healing < 100 and getHealing() + healing >= 0) {
                this->healing += healing;
            }
            else { this->healing = 0; }*/
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
            throw exception("sex is not diferend! using is lowcase 'he' or 'she'");

        }
    }

    void PrintAnimalInfo() {
        string HP;

        if (getHealing() == 0) { HP = "is DEATH!"; }
        else
        {
            HP = to_string(getHealing());
        }

        cout << "NAME: " << getName() << endl
            << "AGE: " << getAge() << " Year!" << endl
            << "its: " << getSex() << endl
            << "HP: " << HP << endl
            << "HP: " << (this->healing == 0 ? "is Death!" : to_string(this->healing))
            << "FOOD: " <<getFood() << endl << endl;
    }
};

class Lion :public Animal{
private:
    int *watIsSky = &skyNowIt;
    int* wathIstemp = &temp;

public:
    Lion(string name, int age, string sex) : Animal(name, age, sex) {}

    void PrintTempReaction() {
        cout << "Reaction of temperature ";
        
        if (*wathIstemp >= 30 and *watIsSky ==1) {
            cout << "is HOOT!" << endl;
        }
        else if (0 < *wathIstemp and *wathIstemp <= 15 ) {
            cout << "is Normal" << endl;
        }
        else if (15 < *wathIstemp and *wathIstemp < 30) {
            cout << "is GOOD!" << endl;
        }
       
        else { cout << "is CHOLD" << endl; }
    }

   
    
};


//Базовый клас роботник 

class Employee {
private:
    string name;
    int age;
    string sex;

public:
    Employee(string name, int age) {
        this->name = name;
        this->age = age;
        if (sex == "man" or sex == "woman") { this->sex = sex; }
        else
        {
            throw exception("is sex ont diferend!using is lowcase 'man' or 'woman' ");

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
    string name;

public:

    Enclouse(int size, string name) { this->size = size; this->name = name; }

    void getInfoEnclouse() {
        for (int i = 0; i < Animals.size(); i++) {
            cout <<"cahe "<<name<< " it " << i << endl;
            Animals[i].PrintAnimalInfo();
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
        Animals[it].PrintAnimalInfo();
        Animals.erase(Animals.begin() + it);
    }

    string getName() { return name; }

    void setName(string name) { this->name = name; }
};




void main()
{

    //try
    //{
    //    Animal cat("Murzik", 3, "she");
    //    Animal dog("Smurf", 4, "he");
    //    Animal chiken("Coco", 6, "he");




    //    Enclouse cage(2,"kyratnik");

    //    cage.AddAnimal(cat);

    //    cage.AddAnimal(dog);

    //    //cage.AddAnimal(chiken);

    //    cage.getInfoEnclouse();

    //    
    //    

    //}
    //catch (const std::exception& err)
    //{
    //    cout << err.what() << endl;
    //}
    //


    /*cout << skyNowIt << endl;
    try
    {
        setSky("rain");
    }
    catch (const std::exception&er)
    {
        cout << er.what();
    }
    
    cout << skyNowIt << endl;*/


    Lion Vasya("Vasya",3, "he");
    Vasya.PrintAnimalInfo();

 

    temp = 32;
    Vasya.PrintTempReaction();
    temp = 13;
    Vasya.PrintTempReaction();
    temp = -17;
    Vasya.PrintTempReaction();
    
};
 
