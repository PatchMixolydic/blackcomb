#ifndef CRAFTCLONE_ENGINEEXCEPTION_H
#define CRAFTCLONE_ENGINEEXCEPTION_H

#include <exception>

class EngineException: public std::exception {
public:
    EngineException(const char* msg);

    virtual const char* what() const throw();

private:
    const char* msg;
};


#endif //CRAFTCLONE_ENGINEEXCEPTION_H
