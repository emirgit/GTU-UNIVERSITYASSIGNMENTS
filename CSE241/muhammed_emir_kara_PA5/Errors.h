#ifndef _ERRORS_H_
#define _ERRORS_H_
#include <exception>


//if file cannot open, throw File open Error
class FileOpenError : public std::exception {
public:
    FileOpenError();
    const char* what() const noexcept override;
};

//other error respect to pdf
class MissingFieldException : public std::exception {
public:
    MissingFieldException();
    const char* what() const noexcept override;
};

class DuplicateEntryException : public std::exception {
public:
    DuplicateEntryException();
    const char* what() const noexcept override;
};

class WrongCommandException : public std::exception {
public:
    WrongCommandException();
    const char* what() const noexcept override;
};

#endif
