#ifndef SECONDRETRYEXCEPTION_H
#define SECONDRETRYEXCEPTION_H

#include <string>
#include <exception>
#include <memory>

class SecondRetryException : public std::exception
{
   std::string m_what;
public:
    SecondRetryException(std::string w = "") { m_what = w; }
    SecondRetryException(const std::exception &e) { m_what = std::string(e.what()); }
    const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override { return m_what.data(); }
};

#endif // SECONDRETRYEXCEPTION_H
