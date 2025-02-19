#include <iostream>

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
    // Strategy_1 st1(std::make_shared<MoveForward>(std::make_shared<NonMovableObject>()));
    // st1.run();

    // Strategy_2 st2(std::make_shared<MoveForward>(std::make_shared<NonMovableObject>()));
    // st1.run();

    // auto result1 = IoC::resolve<Vector2D>("Vector2D.getVector2D", 
    //     std::function<Vector2D(double, double)>([](double x, double y){
    //         return Vector2D(x, y);
    //     }),
    //     2.0,
    //     3.1
    // );

    // auto result2 = IoC::resolve<Vector2D>("Vector2D.getVector2D", 
    //     std::function<void(void)>(),
    //     7.0,
    //     9.1
    // );

        auto result2 = IoC::resolve<Vector2D>("Vector2D.getVector2D", 
        std::function<void(void)>([](){
            std::cout << "asdsads" << std::endl;
        })
    );

    // printf("%f %f\n", result1.x(), result1.y());
    // printf("%f %f\n", result2.x(), result2.y());
    return 0;
}
