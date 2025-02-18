#include "ioc.h"

std::map<std::string, std::shared_ptr<IoCContainerBase>> IoC::m_scope = std::map<std::string, std::shared_ptr<IoCContainerBase>>();


