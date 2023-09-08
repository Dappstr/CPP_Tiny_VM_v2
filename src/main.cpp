#include <iostream>
#include <vector>
#include <string>

#include "../include/fileutil.h"
#include "../include/lex.h"

int main(int argc, char* argv[]) {
    char* path = argv[1];
    
    //Get file contents
    std::string contents = get_file_contents(path);

    //Lex
    std::vector<std::string> lexemes = lex(std::move(contents));
    
    int num_lexemes = 1;
    for(auto& lexeme : lexemes) {
        std::cout << "Lexeme " << num_lexemes << ' ' << lexeme << '\n';
    }

    //Tokenize

    //Parse

    return 0;
}
