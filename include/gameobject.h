#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>

class GameObject
{
public:
    GameObject() {}
};

typedef std::shared_ptr<GameObject> GameObjectPtr;

#endif // GAMEOBJECT_H
