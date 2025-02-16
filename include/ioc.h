#ifndef IOC_H
#define IOC_H

#include <string>
#include <memory>
#include <map>
#include "functional"

template <class T>
class FuncContainer
{

};

class IoC
{
    std::map<std::string, std::map<std::string, int>> m_scopes;

    IoC() = delete;                      //disable constructor
    IoC(const IoC&) = delete;            //disable copy-constructor
    IoC& operator=(const IoC&) = delete; //disable copy-assignment

public:
    template <typename T, typename ... Args> static std::shared_ptr<T> resolve(std::string path, Args&&... args) 
    {
        return std::make_shared<T>(args...);
    }
};

#endif // IOC_H