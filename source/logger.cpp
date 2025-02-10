#include "logger.h"

void Logger::log(std::string text)
{
    printf("%s\n", text.data());
}