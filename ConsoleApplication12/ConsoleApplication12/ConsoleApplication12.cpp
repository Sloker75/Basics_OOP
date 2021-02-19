#include <iostream>

using namespace std;

class VladKrasava{
    
    
    public:
    
    
};

//Шина
class Tire {
public:
    Tire(int diam, int weight, string type) : m_diameterTire{ diam }, m_weightTire{ weight }, m_type{ type } {
    };

    int getDiameterInTire() {
        return m_diameterTire;
    }

    int getWeightInTire() {
        return m_weightTire;
    }

    string getTypeInTire() {
        return m_type;
    }

private:
    string m_type;
    int m_diameterTire;
    int m_weightTire;
};
//Диск
class Disc {
public:
    Disc(int diam, int weight) : m_diameterDisc{ diam }, m_weightDisc{ weight } {};

    int getDiameterInDisc() {
        return m_diameterDisc;
    };

    int getWeightInDisc() {
        return m_weightDisc;
    };

private:
    int m_diameterDisc;
    int m_weightDisc;

};
//Колесо
class Wheel {
public:
    Wheel(Disc disc, Tire tire) : m_Disc{ disc }, m_Tire{ tire }  {};


    int getWeight() {

        return m_Disc.getWeightInDisc() + m_Tire.getWeightInTire();
    }

    void cheek() {
        if (m_Disc.getDiameterInDisc() == m_Tire.getDiameterInTire())
        {
            cout << "Disc == Tire?\nTrue\n";
        }
        else
        {
            cout << "Disc == Tire?\nFalse\n";
        }
    }

    string getTypeInTire()
    {
        return m_Tire.getTypeInTire();
    }

private:
    Disc m_Disc;
    Tire m_Tire;
};
//Двигун
class Engine {
public:
    Engine(int weight, int consumption, int power) : m_weightEngine{ weight }, m_consumption{ consumption }, m_power{ power }
    {

    };
    int getWeghtInEngine() {
        return m_weightEngine;
    };
    int getConsumptionInEngine() {
        return m_consumption;
    }
    int getPowerInEngine() {
        return m_power;
    }



private:
    int m_weightEngine;
    //розхід пального
    int m_consumption;
    //потужність
    int m_power;
};
//Пальне
class Fuel {
public:

    Fuel(int objem, int weight) : m_objem{ objem }, m_weight{ weight }
    {
        strcpy_s(m_type, "lol");
    };
    int getObjemInFuel() {
        return m_objem;
    }

    int getWeightInFuel() {
        return m_weight;
    }

    char* getType()
    {
        return m_type;
    }


protected:
    int m_objem;
    int m_weight;
    char m_type[10];
};
//батарея
class Battery : public Fuel {
public:
    Battery(int obyem, int vaga) : Fuel(obyem, vaga)
    {
        strcpy_s(m_type, "Ah");
    };

};
//Бак
class Back : public Fuel {
public:
    Back(int obyem, int vaga) : Fuel(obyem, vaga)
    {
        strcpy_s(m_type, "Lh");
    };


};
//машина
class Car {
    char m_name[15];
public:


    Car(Fuel* f, Wheel* w, Engine* e) : m_fuel{ f }, m_wheel{ w }, m_engine{ e } {
        strcpy_s(m_name, "Ford");
    };

    void Print()
    {
        cout << "-------------------------------------------------------------------------";
        cout << "\nName - " << m_name << endl;
        cout << "Wheel type - " << m_wheel->getTypeInTire() << endl;
        cout << "Weight a wheels - " << m_wheel->getWeight() << endl;
        cout << "Diameter a wheels - ";
        m_wheel->cheek();
        cout << "Weight the engine - " << m_engine->getWeghtInEngine() << endl;
        cout << "Power the engine - " << m_engine->getPowerInEngine() << endl;
        cout << "Consumption the engine - " << m_engine->getConsumptionInEngine() << endl;
        cout << "Volume the fuel - " << m_fuel->getObjemInFuel() << endl;
        cout << "Weight the fuel - " << m_fuel->getWeightInFuel() << endl;
        cout << "Fuel type - " << m_fuel->getType() << endl;
        cout << "Weight a car - " << m_engine->getWeghtInEngine() + m_fuel->getWeightInFuel() + m_wheel->getWeight() << endl;
        cout << "maximum speed - " << endl;
        cout << "passage on one full tank - " << (m_fuel->getObjemInFuel() / 60) * 100 << endl;
        cout << "-------------------------------------------------------------------------\n\n";
    }



private:
    Fuel* m_fuel;
    Wheel* m_wheel;
    Engine* m_engine;
};

int main()
{
    Tire shuna(19, 2, "sport");
    Disc dusc(19, 3);
    Wheel koleco(dusc, shuna);
    Engine dvugyn(250, 60, 220);
    Fuel* palne = new Back(159, 160);
    Car car(palne, &koleco, &dvugyn);
    car.Print();


    Tire shuna1(16, 2, "winter");
    Disc dusc1(15, 4);
    Wheel koleco1(dusc1, shuna1);
    Engine dvugyn1(190, 80, 190);
    Fuel* palne1 = new Battery(62, 140);
    Car car1(palne1, &koleco1, &dvugyn1);
    car1.Print();
}
