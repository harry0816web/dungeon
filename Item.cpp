#include "Item.h"

// Constructors
Item::Item(){};
Item::Item(string type, string n, int hp, int atk, int def) : type(type), name(n), health(hp), attack(atk), defense(def){};

// event
bool Item::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player *>(obj);
    cout << "this is a " << name << endl;
    // if the item is a weapon, then the player can equip it
    if (type == "sword")
    {
        cout << "do you want to replace it with your weapon?\n";
        cout << "weapon: " << name << '\n';
        cout << "atk: +" << attack << '\n';
        cout << "--------------\n";
        cout << "your weapon: " << player->getWeapon()->getName() << '\n';
        cout << "atk: +" << player->getWeapon()->getAttack() << '\n';
        cout << "y(yes)/n(no): \n";
        char input;
        cin >> input;
        if (input == 'y')
        {
            player->setWeapon(this);
            return true;
        }
        else
        {
            cout << "you don't want this weapon.";
            return false;
        }
    }
    // if the item is a potion, then the player can drink it

    // if the item is a key, then the player can use it

    // if the item is a treasure, then the player can pick it up
    return true;
}

// Getters
string Item::getName()
{
    return name;
}
int Item::getHealth()
{
    return health;
}
int Item::getAttack()
{
    return attack;
}
int Item::getDefense()
{
    return defense;
}

// Setters
void Item::setName(string n)
{
    name = n;
}
void Item::setHealth(int hp)
{
    health = hp;
}
void Item::setAttack(int atk)
{
    attack = atk;
}
void Item::setDefense(int def)
{
    defense = def;
}