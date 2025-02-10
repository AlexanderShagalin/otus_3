#include "moveforward.h"
#include "commandexception.h"
#include "strategy_1.h"
#include "strategy_2.h"

using namespace std;

class NonMovableObject : public IMovable
{
public:
    Vector2D getPosition() override { return Vector2D(0.0, 0.0); }
    Vector2D getVelocity() override { return Vector2D(0.0, 0.0); }
    void setPosition(Vector2D newPosition) override { throw CommandException("Cannot move non-movable object"); }
};


int main()
{
    Strategy_1 st1(std::make_shared<MoveForward>(std::make_shared<NonMovableObject>()));
    st1.run();


    Strategy_2 st2(std::make_shared<MoveForward>(std::make_shared<NonMovableObject>()));
    st1.run();

    return 0;
}
