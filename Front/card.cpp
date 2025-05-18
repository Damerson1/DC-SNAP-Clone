#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Card {
    private:
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

        void onRevealEffect() {

        }

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
};
