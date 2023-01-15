//
// Created by itama on 09/01/2023.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <exception>
#include <string>
#include <stdexcept>

using namespace std;

class DeckFileErrors : public runtime_error {
public:
    explicit DeckFileErrors(const string &what) : runtime_error(what) {
    }
};

class DeckFileNotFound : public DeckFileErrors {
public:
    explicit DeckFileNotFound(const string &what) : DeckFileErrors(what) {
    }
};

class DeckFileFormatError : public DeckFileErrors {
public:
    explicit DeckFileFormatError(const string &what) : DeckFileErrors(what ) {

    }
};

class DeckFileInvalidSize : public DeckFileErrors {
public:
    explicit DeckFileInvalidSize(const string &what) : DeckFileErrors(what) {
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
