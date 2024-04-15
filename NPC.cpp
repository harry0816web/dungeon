#include "NPC.h"

// NPCs

// constructor
NPC::NPC(){};
NPC::NPC(string name, string script, vector<Item> commodity) : GameCharacter(name){};

// event handler
void NPC::listCommodity()
{
    cout << "I have these things: \n";
    for (int i = 0; i < (int)commodity.size(); i++)
    {
        cout << i << ": " << commodity[i].getName() << '\n';
    }
}
bool NPC::triggerEvent(Object *)
{
    cout << "Hi !"
         << "I'm NPC" << endl;
    return true;
}

// setter
void NPC::setCommodity(vector<Item> commodity)
{
    this->commodity = commodity;
}
void NPC::setScript(string script)
{
    this->script = script;
}

// getter
string NPC::getScript()
{
    return this->script;
}
vector<Item> NPC::getCommodity()
{
    return this->commodity;
}