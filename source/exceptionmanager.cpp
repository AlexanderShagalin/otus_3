#include "exceptionmanager.h"

std::map<std::pair<size_t, size_t>, IHandlerPtr> ExceptionManager::m_handlerList;

void ExceptionManager::handle(const std::exception& e, ICommandPtr command) 
{
    auto source = std::make_pair<size_t, size_t>(typeid(*command).hash_code(), typeid(e).hash_code());
    auto it = m_handlerList.find(source);
    if(it != m_handlerList.end())
        it->second->handle(command);
}

void ExceptionManager::registerHandler(ICommandPtr command, std::exception e, IHandlerPtr handler)
{
    auto source = std::make_pair<size_t, size_t>(typeid(*command).hash_code(), typeid(e).hash_code());
    if(m_handlerList.count(source)== 0)
        m_handlerList.insert({ source, handler });
}
