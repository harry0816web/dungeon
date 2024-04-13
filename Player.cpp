#include "Player.h"

// constructor
Player::Player(){};
Player::Player(string name, int maxHealth, int attack, int defense) : GameCharacter(name, maxHealth, maxHealth, attack, defense) {}

// func
void Player::addItem(Item item)
{
    inventory.push_back(item);
}
void Player::increaseStates(int maxHp, int atk, int def)
{
    setMaxHealth(maxHp);
    setAttack(atk);
    setDefense(def);
}
void Player::changeRoom(Room *room)
{
    previousRoom = currentRoom;
    currentRoom = room;
    //??
}

// Virtual func?
bool Player::triggerEvent(Object *obj)
{
    // cout status of the object?
    return true;
}

// setter
void Player::setPreviousRoom(Room *room)
{
    this->previousRoom = room;
}
void Player::setCurrentRoom(Room *room)
{
    this->currentRoom = room;
}
void Player::setInventory(vector<Item> inventory)
{
    this->inventory = inventory;
}

// getter
Room *Player::getPreviousRoom()
{
    return previousRoom;
}
Room *Player::getCurrentRoom()
{
    return currentRoom;
}
vector<Item> Player::getInventory()
{
    return inventory;
}