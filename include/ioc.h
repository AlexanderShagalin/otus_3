#ifndef IOC_H
#define IOC_H

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include "functional"

// template <typename T>
// struct IoCContainer
// {
//     static std::map<std::string, T> relevant_map;
// };

// template <typename T>
// std::map<std::string, T> IoCContainer<T>::relevant_map;


// class IoC
// {
//     IoC() = delete;                      //disable constructor
//     IoC(const IoC&) = delete;            //disable copy-constructor
//     IoC& operator=(const IoC&) = delete; //disable copy-assignment


// public:
//     template <typename Return_Type, typename FuncPtr_Type, typename ... Args> 
//     static Return_Type resolve(std::string path, FuncPtr_Type funcptr, Args ... args) 
//     {

//         if(IoCContainer<FuncPtr_Type>::relevant_map.find(path) == IoCContainer<FuncPtr_Type>::relevant_map.end())
//         {
//             auto lm = [&, args...](FuncPtr_Type obj){
//                 IoCContainer<FuncPtr_Type>::relevant_map.insert({path, obj});
//                 return obj(args...);
//             };
//             return lm(funcptr);
//         }

        
//         return IoCContainer<FuncPtr_Type>::relevant_map.find(path)->second(args...);
//     }
// };


template <typename T>
struct IoCContainer
{
    static std::map<std::string, T> relevant_map;
};

template <typename T>
std::map<std::string, T> IoCContainer<T>::relevant_map;


class IoC
{
    IoC() = delete;                      //disable constructor
    IoC(const IoC&) = delete;            //disable copy-constructor
    IoC& operator=(const IoC&) = delete; //disable copy-assignment


public:
    template <class Return_Type, typename ... Args> 
    static Return_Type resolve(std::string path, Args ... args) 
    {
        // auto func = std::forward<Args>(args);

        auto&& arg = std::get<>(
            std::forward_as_tuple(
                std::forward<Args>(args)...));
        auto lm = [&, arg](){
            IoCContainer<Return_Type>::relevant_map.insert({path, arg});
            return arg();
        };

        // if(IoCContainer<Return_Type>::relevant_map.find(path) == IoCContainer<Return_Type>::relevant_map.end())
        {
        //      auto lm = [&, args...](FuncPtr_Type obj){
        //          IoCContainer<Return_Type, FuncPtr_Type>::relevant_map.insert({path, obj});
        //          return obj(args...);
        //      };

        //     std::cout << "create" << std::endl;
        //      return lm(funcptr);
        }

        // std::cout << "load" << std::endl;
        // return IoCContainer<Return_Type, FuncPtr_Type>::relevant_map.find(path)->second(args...);
         return Return_Type();
    }
};

#endif // IOC_H