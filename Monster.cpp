#include "Monster.h"

// constructor
Monster::Monster(){};
Monster::Monster(string name, int maxHp, int atk, int def) : GameCharacter(name, maxHp, maxHp, atk, def){};

// event handler
bool Monster::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player *>(obj);
    if (player)
    {
        cout << "You are attacked by " << getName() << "!" << endl;
        // combat system
    }
}