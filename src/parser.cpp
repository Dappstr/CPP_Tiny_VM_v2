#include <vector>
#include <iostream>
#include "../include/parser.h"
#include "../include/tokenize.h"

int get_val_from_ident(const std::vector<Binding>& binds, const std::string& identifier) {
    for(int i = 0; i < binds.size(); ++i) {
       if(identifier == binds.at(i).id) {
           return binds.at(i).value;
       }
    }
    std::cerr << "Failed to find identifier: " << identifier << '\n';
    exit(EXIT_FAILURE);
    return 0;
}

void parse(std::vector<Token> &&tokens, std::vector<Binding> &binds, std::vector<int> &stack)
{
    for(int i = 0; i < tokens.size(); ++i) {
        if(tokens.at(i).token_type == TokenType::INST) {
            InstType type = std::get<InstType>(tokens.at(i).m_value);
            switch(type) {
                case InstType::PUSH: {
                    if(tokens.at(i+1).token_type != TokenType::LIT && tokens.at(i+1).token_type != TokenType::IDENT) {
                        std::cerr << "Expected integer literal or identifier after push instruction!\n";
                        std::cout << tokens.at(i+1).token_type;
                        exit(EXIT_FAILURE);
                    }
                    else {
                        if(tokens.at(i+1).token_type == TokenType::LIT) {
                            int value = std::get<int>(tokens.at(i+1).m_value);
                            stack.push_back(value);
                        }
                        else {
                            std::string ident = std::get<std::string>(tokens.at(i+1).m_value);
                            int value = get_val_from_ident(binds, ident);
                            stack.push_back(value);
                        }
                    }
                    i++;
                    break;
                }
                case InstType::PRINT: {
                    std::cout << "[ "; 
                    for(int x = 0; x < stack.size(); ++x) {
                        if(x == stack.size() - 1) {
                            std::cout << stack.at(x) << " ]\n";
                            break;
                        }
                        std::cout << stack.at(x) << ", ";
                    }                          
                }
                case InstType::HALT: {
                    return;
                }
            }
        }
        else if(tokens.at(i).token_type == TokenType::VAR) {
            if(i + 2 < tokens.size() && tokens.at(i+1).token_type == IDENT && tokens.at(i+2).token_type == ASSIGNMENT) {
                std::string var_name = std::get<std::string>(tokens.at(i+1).m_value);
                if(i + 3 < tokens.size() && tokens.at(i+3).token_type == TokenType::LIT) {
                    int value = std::get<int>(tokens.at(i+3).m_value);
                    binds.push_back({var_name, value});
                    i+=3;
                }
                else {
                    std::cerr << "Expected integer literal after '='\n";
                    exit(EXIT_FAILURE);
                }
            }
            else {
                std::cerr << "Expected variable identifier after \"var\\n";
                exit(EXIT_FAILURE);
            }
        }
    }
}
