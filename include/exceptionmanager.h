#ifndef EXCEPTIONMANAGER_H
#define EXCEPTIONMANAGER_H

#include <exception>
#include <memory>
#include <utility>
#include <map>  
#include "icommand.h"
#include "ihandler.h"
#include "commandexception.h"

class ExceptionManager
{
    static std::map<std::pair<std::type_info, std::type_info>, IHandlerPtr> m_handlerList;
public:
    ~ExceptionManager(){}
    void handle(const std::exception& e, ICommandPtr command);

    static void registerHandler(std::pair<std::type_info, std::type_info> source, IHandlerPtr handler);
};

typedef std::shared_ptr<ExceptionManager> ExceptionManagerPtr;
#endif // EXCEPTIONMANAGER_H
