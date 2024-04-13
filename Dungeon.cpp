#include "Dungeon.h"

#include <iostream>
#include <vector>
using namespace std;

// classes to build characters
class character
{
private:
    string name;
    int hp;
    int atk;
    int def;
    vector<item> items; // A class "character" has a list of objects from the class "item".
public:
    void set_name(string n) { name = n; }
    string get_name() { return name; }
};
class player : public character
{
private:
    int lvl;

public:
    void set_lvl(int i) { lvl = i; }
    int get_lvl() const { return lvl; }
};

class monster : public character
{
private:
    double exp;

public:
    void set_exp(double e) { exp = e; }
};

class item
{
private:
    string name;
    int value;

public:
};

int main()
{
}