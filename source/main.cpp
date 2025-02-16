#include "moveforward.h"
#include "commandexception.h"
#include "strategy_1.h"
#include "strategy_2.h"

#include "ioc.h"

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

    auto obj = IoC::resolve<Vector2D>("Vector2D", 7.0, 10.1);
    printf("%f %f\n", obj->x(), obj->y());
    return 0;
}
