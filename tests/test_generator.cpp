#include <ioc.h>
#include <icommand.h>
#include <resolvercontainer.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <FueledAdapter.h>
#include <stdexcept>
#include <iresolvercontainer.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::InSequence;

class GO : public GameObject
{
public:
    MOCK_METHOD(void, func, ());
 };

TEST(Generator, CreateClasses)
{
    GameObjectPtr obj = std::make_shared<GameObject>();
    IoC::Resolve<ICommandPtr>("IoC.Scope.Current.Set", "/")->execute();

    FueledAdapter::Register();

    auto adapter = IoC::Resolve<std::shared_ptr<FueledAdapter>>("Fueled", obj);

    EXPECT_NE( adapter, nullptr );
}

TEST(Generator, UsageFunction)
{
    std::shared_ptr<GO> obj = std::make_shared<GO>();
    IoC::Resolve<ICommandPtr>("IoC.Scope.Current.Set", "/")->execute();

//    FueledAdapter::Register();
    IoC::Resolve<ICommandPtr>(
        "IoC.Register",
        "Fueled.FuelCount.set",
        make_container(std::function<void(GameObjectPtr, int)>( [](GameObjectPtr obj, int count){
                           count++;
                           auto d = std::static_pointer_cast<GO>(obj);
                           if(d)
                           {
                                d->func();
                           }
                       } ))
        )->execute();


    auto adapter = IoC::Resolve<std::shared_ptr<FueledAdapter>>("Fueled", std::dynamic_pointer_cast<GameObject>(obj));
    EXPECT_CALL(*obj, func());

    adapter->setFuelCount(2);

}
