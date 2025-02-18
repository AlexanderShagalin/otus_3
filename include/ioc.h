#ifndef IOC_H
#define IOC_H

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include "functional"


class IoCContainerBase
{
public:    
    virtual ~IoCContainerBase() {}
};

template <typename T>
class IoCContainer : public IoCContainerBase
{
public:
    T func;
};

class IoC
{
    static std::map<std::string, std::shared_ptr<IoCContainerBase>> m_scope;

    IoC() = delete;                      //disable constructor
    IoC(const IoC&) = delete;            //disable copy-constructor
    IoC& operator=(const IoC&) = delete; //disable copy-assignment


public:
    template <typename Return_Type, typename FuncPtr_Type, typename ... Args> 
    static std::shared_ptr<Return_Type> resolve(std::string path, FuncPtr_Type lambda , Args&& ... args) 
    {
        // auto lx = [&, lambda, args...](){ 
        //     return (*lambda)(args...);
        // };

        if(m_scope.find(path) == m_scope.end())
        {
            auto  cont = std::make_shared<IoCContainer<FuncPtr_Type>>();
            cont->func = lambda;
            m_scope.insert({path, cont});
            return nullptr;
        }
        
        auto x = std::dynamic_pointer_cast<IoCContainer<FuncPtr_Type>>(m_scope.find(path)->second);
        if(x != nullptr)
        {
            std::cout << "Done" << std::endl;
            // return x->func(3.0, 2.0);            
            return x->func(args...);
        }
        else
            std::cout << "Error" << std::endl;
        
        return nullptr;
    }
};

#endif // IOC_H