#ifndef IOC_H
#define IOC_H

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <functional>
#include <stdexcept>

struct IoCItemBase {
    virtual ~IoCItemBase() = default;
 };

template <typename Function_type>
struct IoCItem : IoCItemBase
{
    Function_type execute;
};

class IoC
{
    IoC() = delete;                      //disable constructor
    IoC(const IoC&) = delete;            //disable copy-constructor
    IoC& operator=(const IoC&) = delete; //disable copy-assignment


public:
    static std::map<std::string, std::shared_ptr<IoCItemBase>> IoCItems;

    template <typename Return_Type, typename ... Args>
    static Return_Type __resolve(std::string path, Args ... args)
    {
        auto item = IoC::IoCItems.find(path);
        if(item == IoC::IoCItems.end())
        {
            using funcTypeName = std::tuple_element_t<0, std::tuple<Args...>>;
            auto func = std::get<0>(std::tuple<Args...>(args...));
            auto item = std::make_shared<IoCItem<funcTypeName>>();
            item->execute = func;
            IoC::IoCItems.insert({path, item});
            return nullptr;
        }
        
        using MyFunc_Type = IoCItem<std::function<Return_Type(Args...)>>;

        auto resolved = std::dynamic_pointer_cast<MyFunc_Type>(item->second);
        if(resolved != nullptr)
        {
            return resolved->execute(args...);
        }
        else
        {
            std::cout << "not resolved" << std::endl;
            throw std::runtime_error("not resolved");
        }

        return nullptr;
    }

    template <typename Return_Type>
    static Return_Type __resolve(std::string path)
    {
        auto item = IoC::IoCItems.find(path);
        if(item == IoC::IoCItems.end())
        {
            throw std::runtime_error("not resolved");
            return nullptr;
        }

        using MyFunc_Type = IoCItem<std::function<Return_Type()>>;

        auto resolved = std::dynamic_pointer_cast<MyFunc_Type>(item->second);
        if(resolved != nullptr)
        {
            return resolved->execute();
        }
        else
        {
            std::cout << "not resolved" << std::endl;
            throw std::runtime_error("not resolved");
        }

        return nullptr;
    }
};


#endif // IOC_H