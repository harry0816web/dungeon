#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter : public Object
{
private:
    string name;
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;

public:
    GameCharacter();
    GameCharacter(string n, int maxHp = 10, int curHp = 10, int atk = 10, int def = 10);
    bool checkIsDead();
    int takeDamage(int);

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setDefense(int);
    int getMaxHealth() const;
    int getCurrentHealth() const;
    int getAttack() const;
    int getDefense() const;
};
#endif // GAMECHARACTER_H_INCLUDEDw
