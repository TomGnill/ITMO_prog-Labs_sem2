#pragma once
#include <exception>
class Exception : public std::exception {
public:
    Exception(char* error_message) :

        error_message_(error_message) {};
    virtual const char* what() const noexcept override {
        return  error_message_;
    }
private:
    char* error_message_;
};