#include "blackcomb/misc/BlackcombException.h"

BlackcombException::BlackcombException(const char* msg) : msg(msg) {}

const char* BlackcombException::what() const throw() {
    return msg;
}
