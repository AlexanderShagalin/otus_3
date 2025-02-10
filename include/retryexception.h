#ifndef RETRYEXCEPTION_H
#define RETRYEXCEPTION_H

#include <exception>
#include <memory>
#include "icommand.h"

class RetryException : public std::exception
{
   std::string m_what;
public:
    RetryException(std::string w = "") { m_what = w; }
    RetryException(const std::exception &e) { m_what = std::string(e.what()); }
    const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override { return m_what.data(); }
};

#endif // RETRYEXCEPTION_H
