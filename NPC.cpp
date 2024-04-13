#include "NPC.h"

// NPCs
class NPC_Seller : public NPC
{
};

// constructor
NPC::NPC(){};
NPC::NPC(string name, string script, vector<Item> commodity) : GameCharacter(name){};

// event handler

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