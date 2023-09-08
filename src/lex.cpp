#include <ctype.h>
#include <cstdlib>
#include <ctype.h>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> lex(std::string&& contents) {
    std::string lexeme;
    std::vector<std::string> lexemes;

    for(int i = 0; i < contents.size(); ++i) {
        if(isspace(contents.at(i))) {
            if(!lexeme.empty()) {
                lexemes.push_back(lexeme);
                lexeme.clear();
            }
            continue;
        }
        if(isalpha(contents.at(i))) {
            while(isalpha(contents.at(i))) {
                lexeme.push_back(contents.at(i));
                ++i;
            }
            --i;
            lexemes.push_back(lexeme);
            lexeme.clear();
        }
        else if(isdigit(contents.at(i))) {
            while(isdigit(contents.at(i))) {
                lexeme.push_back(contents.at(i));
                ++i;
            }
            lexemes.push_back(lexeme);
            lexeme.clear();
            --i;
        }
        else if(contents.at(i) == '#' || contents.at(i) == '(' || contents.at(i) == ')' || contents.at(i) == '=') {
            lexeme.push_back(contents.at(i));
            lexemes.push_back(lexeme);
            lexeme.clear();
        }
        else {
            std::cerr << "Encountered unexpected lexeme: " << contents.at(i) << " while lexing!\n";
            exit(EXIT_FAILURE);
        }
    }

    return lexemes;
}
