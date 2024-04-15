#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

struct RoomType
{
    string system;
    string type;
    // string description;
};

class Room
{
private:
    Room *upRoom = nullptr;
    Room *downRoom = nullptr;
    Room *leftRoom = nullptr;
    Room *rightRoom = nullptr;
    bool isExit;
    int index;
    RoomType type;
    vector<Object *> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room();
    Room(bool, RoomType, int, vector<Object *>);
    bool popObject(Object *); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setUpRoom(Room *);
    void setDownRoom(Room *);
    void setLeftRoom(Room *);
    void setRightRoom(Room *);
    void setUDRoom(Room *down);
    void setLRRoom(Room *right);
    void setIsExit(bool);
    void setType(RoomType);
    void setIndex(int);
    void setObjects(vector<Object *>);
    bool getIsExit();
    int getIndex();
    string getSys();
    string getType();
    vector<Object *> getObjects();
    Room *getUpRoom();
    Room *getDownRoom();
    Room *getLeftRoom();
    Room *getRightRoom();
    vector<string> getExit();
};

#endif // ROOM_H_INCLUDED
