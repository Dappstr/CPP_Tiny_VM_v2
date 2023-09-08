#include <iostream>

#include "../include/fileutil.h"

int main(int argc, char* argv[]) {
    char* path = argv[1];
    
    std::string contents = get_file_contents(path);

    std::cout << "Read:\n" << contents;

    return 0;
}
