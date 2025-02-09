#ifndef EXCEPTIONMANAGER_H
#define EXCEPTIONMANAGER_H

#include <exception>
#include <memory>
#include <utility>
#include <map>
#include <list>
#include "icommand.h"
#include "ihandler.h"

class ExceptionManager
{
    static std::map<std::pair<size_t, size_t>, IHandlerPtr> m_handlerList;
public:
   void handle(const std::exception& e, ICommandPtr command);

    // static void registerHandler(std::pair<std::type_info, std::type_info> source, IHandlerPtr handler);
    static void registerHandler(ICommandPtr command, std::exception e, IHandlerPtr handler);
};

typedef std::shared_ptr<ExceptionManager> ExceptionManagerPtr;
#endif // EXCEPTIONMANAGER_H
