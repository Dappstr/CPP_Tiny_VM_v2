#include <iostream>
#include <vector>
#include <string>

#include "../include/fileutil.h"
#include "../include/lex.h"
#include "../include/tokenize.h"

int main(int argc, char* argv[]) {
    char* path = argv[1];
    
    //Get file contents
    std::string contents = get_file_contents(path);

    //Lex
    std::vector<std::string> lexemes = lex(std::move(contents));

    //Tokenize
    std::vector<Token> tokens = tokenize(std::move(lexemes));

    //Parse

    return 0;
}
