#ifndef LOGEXCEPTION_H
#define LOGEXCEPTION_H

#include <string>
#include <exception>
#include <memory>

class LogException : public std::exception
{
   std::string m_what;
public:
    LogException(std::string w = "") { m_what = w; }
    LogException(const std::exception &e) { m_what = std::string(e.what()); }
    const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override { return m_what.data(); }
};

#endif // LOGEXCEPTION_H
