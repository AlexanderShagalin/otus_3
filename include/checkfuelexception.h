#ifndef CHECKFUELEXCEPTION_H
#define CHECKFUELEXCEPTION_H

#include <string>
#include <exception>
#include <memory>

class CheckFuelException : public std::exception
{
   std::string m_what;
public:
    CheckFuelException(std::string w = "") { m_what = w; }
    CheckFuelException(const std::exception &e) { m_what = std::string(e.what()); }
    const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override { return m_what.data(); }
};

#endif // CHECKFUELEXCEPTION_H
