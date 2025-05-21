#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Card {
protected:
        // Card ID
        int id;
        string name;
        int power;
        int cost;

public:
        Card(int id, string name, int power, int cost)
            : id(id), name(name), power(power), cost(cost) {
            if (power < 0) {
                cerr << "Error: power value cannot be negative. Setting to 0." << std::endl;
                this->power = 0;
            }
        }

        virtual void onRevealEffect() {
            cout << name << "Has no effect." << endl;
        }
        
        //Used for JSON serialization with react
        virtual string toJSON() const;

        int getId() const {
            return id;
        }

        string getName() const {
            return name;
        }

        int getPower() const {
            return power;
        }

        int getCost() const {
            return cost;
        }

        void printInfo() const {
            cout << "Card ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Power: " << power << endl;
            cout << "Cost: " << cost << endl;
        }
};

class superman : public Card{
public:
        superman() : Card(1, "superman", 6, 4) {}

        void onRevealEffect() override {
            cout << "I am Earth's Protector" << endl;
        }

        string toJSON() const override {
            return "{ \"id\":1,\"name\":\"superman\",\"power\":6,\"cost\":4}"; 
        }
};
