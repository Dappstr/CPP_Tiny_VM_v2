#include <vector>
#include <string>
#include <ctype.h>
#include <iostream>

#include "../include/tokenize.h"

std::vector<Token> tokenize(std::vector<std::string>&& lexemes) {
    std::vector<Token> tokens;
    
    for(int i = 0; i < lexemes.size(); ++i) {
        if(lexemes.at(i) == "var") {
            tokens.push_back({TokenType::VAR, 0});
        }
        
        //TODO math instructions
        else if(lexemes.at(i) == "push" || lexemes.at(i) == "print" || lexemes.at(i) == "halt") {
            if(lexemes.at(i) == "push") {
                tokens.push_back({TokenType::INST, InstType::PUSH});
            }
            else if(lexemes.at(i) == "print") {
                tokens.push_back({TokenType::INST, InstType::PRINT});
            }
            else if(lexemes.at(i) == "halt") {
                tokens.push_back({TokenType::INST, InstType::HALT});
            }
        }

        else if(lexemes.at(i) == "=") {
            tokens.push_back({TokenType::ASSIGNMENT, 0});
        }

        else if(lexemes.at(i) == "#") {
            if(i + 1 < lexemes.size()) {
                try {
                    int value = std::stoi(lexemes.at(i + 1));
                    tokens.push_back({TokenType::LIT, value});
                    ++i;
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Failed to get number after '#'\n" << e.what() << '\n';
                    exit(EXIT_FAILURE);
                }
            }
        }

        else {
            try {
                int num = std::stoi(lexemes.at(i));
                tokens.push_back({TokenType::LIT, num});
            } catch (const std::invalid_argument& e) {
                tokens.push_back({TokenType::IDENT, lexemes.at(i)});
            }
        }
    }

    return tokens;
}
