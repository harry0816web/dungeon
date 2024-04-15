#include "Object.h"

// constructor
Object::Object(){};
Object::Object(string n, string t) : name(n), tag(t){};

// setter
void Object::setName(string n)
{
    name = n;
}
void Object::setTag(string t)
{
    tag = t;
}

// getter
string Object::getName()
{
    return name;
}
string Object::getTag()
{
    return tag;
}