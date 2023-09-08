#pragma once

#include <variant>
#include <vector>
#include <string>

enum TokenType {
    INST,       //Instruction
    VAR,        //Variable
    IDENT,      //Variable identifier
    ASSIGNMENT, //Assignment operator '='
    LIT,        //Literal
};

enum InstType {
    ADD,
    ALLOC,      //TODO
    DEALLOC,    //TODO
    PUSH,
    PRINT,
    HALT,
};

struct Token {
    TokenType token_type;
    std::variant<int, std::string, InstType> m_value;
};

std::vector<Token> tokenize(std::vector<std::string>&& lexemes);
