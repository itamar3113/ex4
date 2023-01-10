//
// Created by itama on 09/01/2023.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <exception>
#include <string>
#include <stdexcept>

using namespace std;

class DeckFileNotFound : public runtime_error {
public:
    explicit DeckFileNotFound(const string &what) : runtime_error(what) {
    }
};

class DeckFileFormatError : public runtime_error {
public:
    explicit DeckFileFormatError(const string &what) : runtime_error(what) {
    }
};

class DeckFileInvalidSize : public runtime_error {
public:
    explicit DeckFileInvalidSize(const string &what) : runtime_error(what) {
    }
};

class InvalidClassException : public runtime_error {
public:
    explicit InvalidClassException(const string &what) : runtime_error(what) {
    }
};

class InvalidPlayerNameException : public runtime_error {
public:
    explicit InvalidPlayerNameException(const string &what) : runtime_error(what) {
    }
};

class InvalidCardNameException : public runtime_error {
public:
    explicit InvalidCardNameException(const string &what) : runtime_error(what) {
    }
};




#endif //EX4_EXCEPTION_H
