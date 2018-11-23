#include "blackcomb/misc/BlackcombException.h"

namespace blackcomb::misc {
    BlackcombException::BlackcombException(const char* msg) : msg(msg) {}

    const char* BlackcombException::what() const throw() {
        return msg;
    }
}
