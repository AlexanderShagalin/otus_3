// #include <iostream>
// #include "moveforward.h"
// #include "commandexception.h"
// #include "strategy_1.h"
// #include "strategy_2.h"

// #include "ioc.h"

using namespace std;

// class NonMovableObject : public IMovable
// {
// public:
//     Vector2D getPosition() override { return Vector2D(0.0, 0.0); }
//     Vector2D getVelocity() override { return Vector2D(0.0, 0.0); }
//     void setPosition(Vector2D newPosition) override { throw CommandException("Cannot move non-movable object"); }
// };


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
    //     std::function<Vector2D(double, double)>(),
    //     7.0,
    //     9.1
    // );

    // IoC::Init();
    // IoC::resolve<std::shared_ptr<Vector2D>>("Vector2D.getVector2D", std::function<std::shared_ptr<Vector2D>(double, double)>([](double x, double y){
    //     auto vec = std::make_shared<Vector2D>(x, y);
    //     return vec;
    // })
    // );

    // auto result_1 = IoC::resolve<std::shared_ptr<Vector2D>>("Vector2D.getVector2D", 10.4, 4.9);

    // if(result_1)
    //     printf("%f %f\n", result_1->x(), result_1->y());


    // IoC::resolve<void>("Scopes.New", std::string("my_scope"));
    // IoC::resolve<void>("Scopes.Current", std::string("my_scope"));

    // IoC::resolve<std::shared_ptr<Vector2D>>("Vector2D.getVector2D_1", std::function<std::shared_ptr<Vector2D>()>([](){
    //     auto vec = std::make_shared<Vector2D>();
    //     return vec;
    // })
    // );

    // auto result_2 = IoC::resolve<std::shared_ptr<Vector2D>>("Vector2D.getVector2D_1");

    // if(result_2)
    //     printf("%f %f\n", result_2->x(), result_2->y());
        
    // IoC::resolve<void>("Scopes.Current", std::string("root"));

    return 0;
}
