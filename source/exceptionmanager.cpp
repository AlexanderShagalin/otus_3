#include "exceptionmanager.h"

std::map<std::pair<std::type_info, std::type_info>, IHandlerPtr> ExceptionManager::m_handlerList = 
            std::map<std::pair<std::type_info, std::type_info>, IHandlerPtr>();

void ExceptionManager::handle(const std::exception& e, ICommandPtr command) 
{
    auto it = m_handlerList.count(std::make_pair<std::type_info, std::type_info>(typeid(command), typeid(e)));
    if(it != m_handlerList.end())
        *it();
}

void ExceptionManager::registerHandler(std::pair<std::type_info, std::type_info> source, IHandlerPtr handler);
{
    auto it = m_handlerList.count(source);
    if(it == m_handlerList.end())
        m_handlerList.append(source, handler)

}
