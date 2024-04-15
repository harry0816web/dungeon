#include "Room.h"

// constructor
Room::Room(){};
Room::Room(bool exit, RoomType type, int id, vector<Object *> contains) : isExit(exit), type(type), index(id), objects(contains){};

// after event over, pop object
bool Room::popObject(Object *)
{
    this->objects.pop_back();
    return true;
}
vector<string> Room::getExit()
{
    vector<string> exit;
    if (this->upRoom != nullptr)
    {
        exit.push_back("Up");
    }
    if (this->rightRoom != nullptr)
    {
        exit.push_back("Right");
    }
    if (this->downRoom != nullptr)
    {
        exit.push_back("Down");
    }
    if (this->leftRoom != nullptr)
    {
        exit.push_back("Left");
    }
    return exit;
}

// setter
void Room::setIsExit(bool exit)
{
    isExit = exit;
}
void Room::setIndex(int id)
{
    index = id;
}
void Room::setObjects(vector<Object *> contains)
{
    objects = contains;
}
void Room::setUpRoom(Room *upRoom)
{
    this->upRoom = upRoom;
}
void Room::setDownRoom(Room *downRoom)
{

    this->downRoom = downRoom;
}
void Room::setLeftRoom(Room *leftRoom)
{

    this->leftRoom = leftRoom;
}
void Room::setRightRoom(Room *rightRoom)
{

    this->rightRoom = rightRoom;
}
void Room::setUDRoom(Room *down)
{
    this->setDownRoom(down);
    down->setUpRoom(this);
}
void Room::setLRRoom(Room *right)
{
    this->setRightRoom(right);
    right->setLeftRoom(this);
}
void Room::setType(RoomType type)
{
    this->type = type;
}

// getter
bool Room::getIsExit()
{
    return isExit;
}
int Room::getIndex()
{
    return index;
}
string Room::getSys()
{
    return type.system;
}
string Room::getType()
{
    return type.type;
}
// string Room::getDescription()
// {
//     return description;
// }
vector<Object *> Room::getObjects()
{
    return objects;
}
Room *Room::getUpRoom()
{
    return upRoom;
}
Room *Room::getDownRoom()
{
    return downRoom;
}
Room *Room::getLeftRoom()
{
    return leftRoom;
}
Room *Room::getRightRoom()
{
    return rightRoom;
}
