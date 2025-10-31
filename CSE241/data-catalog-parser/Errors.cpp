#ifndef _ERRORS_
#define _ERRORS_

#include "Errors.h"

FileOpenError::FileOpenError() {

}

//error constructor and return message respect to pdf 
const char* FileOpenError::what() const noexcept {
    return "Exception: file open error";
}

MissingFieldException::MissingFieldException() {

}

const char* MissingFieldException::what() const noexcept {
    return "Exception: missing field";
}

DuplicateEntryException::DuplicateEntryException() {

}

const char* DuplicateEntryException::what() const noexcept {
    return "Exception: duplicate entry";
}

WrongCommandException::WrongCommandException() {
    
}

const char* WrongCommandException::what() const noexcept {
    return "Exception: command is wrong";
}

#endif