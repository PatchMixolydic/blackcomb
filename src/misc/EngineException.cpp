#include <blackcomb/misc/EngineException.h>

EngineException::EngineException(const char* msg) : msg(msg) {}

const char* EngineException::what() const throw() {
    return msg;
}
