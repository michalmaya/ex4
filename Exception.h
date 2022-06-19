//
// Created by shayr on 15/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H
#include "string"


class DeckFileNotFound : public std::exception
{
public:
    const char * what() const noexcept override{
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception
{
public:
    explicit DeckFileFormatError(int row) {
        m_msg = "Deck File Error: File format error in line " + std::to_string(row);
    };
    const char * what() const noexcept override{
        return m_msg.c_str();
    }
private:
    std::string m_msg;
};

class DeckFileInvalidSize : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};

#endif //EX4_EXCEPTION_H
