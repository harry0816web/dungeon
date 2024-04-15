#include "Dungeon.h"

// constructor
Dungeon::Dungeon(){};

// initialize the dungeon
void Dungeon::createPlayer()
{
    cout << "Enter your name: ";
    string n;
    cin >> n;
    // 職業 攻擊力高、防禦力高之類ㄉ，反正就初始值不一樣
    this->player = Player(n, 100, 20, 20);
    cout << "Hi! " << this->player.getName() << endl;
    if (this->player.triggerEvent(static_cast<Object *>(&this->player)))
    {
    };
}
void Dungeon::createMap()
{
    // 四個象限分別代表四個生態系
    // 但房間排列不一定是正方形
    Room room1(false, {"forest", "monster"}, 0, vector<Object *>{new Item("weapon", "blade", 10, 0, 0)});
    Room room2(false, {"dessert", "NPC"}, 0, vector<Object *>{new Item("whatever", "item2", 0, 0, 0)});
    Room room3(false, {"swamp", "Item"}, 0, vector<Object *>{new Item("weapon", "sword", 10, 0, 0)});
    Room room4(false, {"ground", "normal"}, 0, vector<Object *>{});

    // set rooms to each other
    room1.setLRRoom(&room2);

    // push to rooms
    rooms.push_back(room1);
    rooms.push_back(room2);
}
void Dungeon::handleMovement()
{
    // 移動
    // 移動後，檢查是否有物件
    // 有物件，則顯示物件資訊
    // 沒有物件，則顯示房間資訊
    // get connection between doors and print the doors
    cout << "You can move to :" << '\n';
    int size = player.getCurrentRoom()->getExit().size();
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ": " << player.getCurrentRoom()->getExit()[i] << '\n';
    }
    cout << "Enter direction: " << endl;
    int direction;
    cin >> direction;
    string dir = player.getCurrentRoom()->getExit()[direction - 1];
    if (dir == "Up")
    {
        player.changeRoom(player.getCurrentRoom()->getUpRoom());
    }
    else if (dir == "Right")
    {
        player.changeRoom(player.getCurrentRoom()->getRightRoom());
    }
    else if (dir == "Left")
    {
        player.changeRoom(player.getCurrentRoom()->getLeftRoom());
    }
    else
    {
        player.changeRoom(player.getCurrentRoom()->getDownRoom());
    }
}
void Dungeon::handleEvent(Object *obj)
{
    // check event and pop obj
    // check event
    Room *room = player.getCurrentRoom();
    vector<Object *> objects = room->getObjects();
    if (room->getType() == "Item")
    {
        if (objects[0]->triggerEvent(&player))
        {
            room->popObject(objects[0]);
        }
    }
}
// game initialization
void Dungeon::startGame()
{
    createMap();
    createPlayer();
    player.setCurrentRoom(&rooms[0]);
}
// game loop
void Dungeon::chooseAction(vector<Object *>)
{
    // 運用obj
    cout << "What you gonna do?" << '\n';
    cout << "1. Move" << '\n';
    cout << "2. Check Status" << '\n';
    cout << "3. Talk to Shop" << '\n';
    cout << "4. Open Backpack" << '\n';
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1: // move
        handleMovement();
        break;
    case 2: // check status
        if (player.triggerEvent(&player))
        {
        }
        break;
    case 3: // talk to shop
        cout << "Talk to shop." << '\n';
        break;
    case 4: // open backpack
        cout << "Open backpack." << '\n';
        break;
    }
}
bool Dungeon::checkGameLogic()
{
    // cout << "checking...";
    if (player.checkIsDead())
    {
        cout << "you lose..." << '\n';
        return false;
    }
    else if (player.getCurrentRoom()->getIsExit())
    {
        cout << "you've made it to the exit!!";
        return false;
    }
    cout << "true";
    return true;
}

// whole game process
void Dungeon::runDungeon()
{
    startGame();
    cout << "Welcome to the dungeon!" << '\n';
    while (checkGameLogic())
    {
        cout << "You are in the " << player.getCurrentRoom()->getType() << " of the " << player.getCurrentRoom()->getSys() << " system." << '\n';
        chooseAction(player.getCurrentRoom()->getObjects());
    }
}