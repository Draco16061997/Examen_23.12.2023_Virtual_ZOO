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
          /*  << "HP: " << (this->healing == 0 ? "is Death!" : to_string(this->healing))*/
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

class Pinguin : public Animal {
private:
    int* watIsSky = &skyNowIt;
    int* wathIstemp = &temp;
public:
    void PrintTempReaction() {
        cout << "Reaction of temperature ";

        if (*wathIstemp >= 30 and *watIsSky == 1) {
            cout << "is HOOT!" << endl;
        }
        else if (0 < *wathIstemp and *wathIstemp <= 15) {
            cout << "is Normal" << endl;
        }
        else if (15 < *wathIstemp and *wathIstemp < 30) {
            cout << "is GOOD!" << endl;
        }

        else { cout << "is CHOLD" << endl; }
    }
};


// От класа Анимал строим другие класи животних

//Базовый клас роботник 

class Human {
private:
    string name;
    int age;
    string sex;

public:
    Human(string name, int age, string sex) {
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

    virtual void PrintInfo() {
        cout <<"Name: "<< getName() << endl
             <<"Age: "<< getAge() << endl
             <<"Sex: "<< getSex() << endl;
    }
};

class Guest :public Human {
private:
    float money;

public:
    Guest(string name, int age, string sex, float money) : Human(name, age, sex){
        this->money = money;
    }

    float GetMoney() { return money; }

    void AddMoney(float money) {
        this->money + money >= 0 ? this->money += money : throw exception("No money!");
    }

    void PrintInfo() override {
        cout << "Name: " << getName() << endl
            << "Age: " << getAge() << endl
            << "Sex: " << getSex() << endl<<
            "money: " << this->money << endl;
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

    void PrintInfoEnclouse() {
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


class Zoo {
private:
    vector<Enclouse> Enclouses;
    vector<Human>Emploues;
    vector<Guest> Guests;
    float money;
    int food;
    float cost;

public:
    Zoo(float money, int food, float cost) {
        this->money = money;
        this->food = food;
        this->cost = cost;
    }


    void addMoney(float money) {
        this->money + money >= 0 ? this->money += money : throw exception("no money");
    }

    float getMoney() { return money; }


    void addFood(int food) {
        this->food + food >= 0 ? this->money += money : throw exception("no food");
    }

    int getFood() { return food; }


    void AddEmplouse(Human emplouse) {
        Emploues.push_back(emplouse);
        emplouse.PrintInfo();
        cout << "ADD!!!" << endl;
    }

    void RemoveEmplouse(int id) {
        if (id < Emploues.size()) {
            Emploues.erase(Emploues.begin() + id);
            cout << id << " DELETED!" << endl;
        }
        else { cout << "Not DELETED!"<<endl; }
    }

    void PrintInfoEmplouse() {
        for (int i = 0; i < Emploues.size(); i++) {
            cout << "===============================" << endl;
            cout << "id: " << i << endl;
            Emploues[i].PrintInfo();
            cout << "===============================" << endl;
        }
    }


    void AddGuest(Guest guest) {
        if (guest.GetMoney() > this->cost) {
            guest.AddMoney(-cost);
            Guests.push_back(guest);
            this->money += cost;
            cout << guest.getName() <<" Welcome to ZOO!!!" << endl;
        }
        else
        {
            cout << guest.getName() << " No Money! " << endl;
        }
    }

    void PrintInfoGuest() {
        if (not Guests.empty()) {
            for (int i = 0; i < Guests.size(); i++) {
                cout << "===============================" << endl;
                cout << "id: " << i << endl;
                Guests[i].PrintInfo();
                cout << "===============================" << endl;
            }
        }
        else { cout << "is Not Guset!!!" << endl; }
       
    
    }

    void RemoveGuest(int id) {
        if (id < Guests.size()) {
            Guests.erase(Guests.begin() + id);
            cout << id << " DELETED!" << endl;
        }
        else { cout << "Not DELETED!" << endl; }
    }


    void AddEnclouse(Enclouse enclouse) {
        Enclouses.push_back(enclouse);
        cout <<enclouse.getName()<< " Add enclouses" << endl;
        
        enclouse.PrintInfoEnclouse();
    }

    void RemoveEnclouse(int id) {
        if (id < Enclouses.size()) {
            cout << "id: " << id << " name: " << Enclouses[id].getName() << " DELETED!" << endl;
            Enclouses.erase(Enclouses.begin() + id);
            
        }
        else { cout << "Not DELETED!" << endl; }
    }

    void PrintEnclouseInfo() {
        if (not Enclouses.empty()) {
            for (int i = 0; i < Enclouses.size(); i++) {
                cout << "===============================" << endl;
                cout << "id: " << i << endl;
                cout<<Enclouses[i].getName()<< endl;
                cout << "===============================" << endl;
            }
        }
        else { cout << "is Not Guset!!!" << endl; }
    }



};



void main()
{



    Lion Vasya("Vasya",3, "he");
   

    Lion Petya("Petya", 4, "he");

    temp = 32;
    
    Vasya.PrintAnimalInfo();
    Petya.PrintAnimalInfo();

    Petya.addHealing(-40);

    Vasya.PrintAnimalInfo();
    Petya.PrintAnimalInfo();
    Human Grisha("Grisha", 23, "man");
    Guest Yriy("Yriy", 25, "man",300);
    Enclouse ku(3, "kuratnik");
    Zoo zoo(122, 12, 10);

   
    zoo.AddGuest(Yriy);
    zoo.PrintInfoGuest();
    zoo.RemoveGuest(0);
    zoo.PrintInfoGuest();
    zoo.AddEnclouse(ku);
    zoo.PrintEnclouseInfo();
    zoo.RemoveEnclouse(0);
};
 
