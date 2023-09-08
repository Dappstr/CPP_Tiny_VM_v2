#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

#include "../include/fileutil.h"

std::string get_file_contents(const char* path) {
    if(!path) {
        std::cerr << "Failed to get file path!\n";
        exit(EXIT_FAILURE);
    }

    std::fstream file(path, std::ios::in);
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    if(size == 0) {
        std::cerr << "Failed getting file size!\n";
        exit(EXIT_FAILURE);
    }

    else if(size == 1) {
        std::cerr << "File contains only EOF!\n";
        exit(EXIT_FAILURE);
    }

    std::string contents(size, '\0');
    
    if(!file.read(&contents[0], size)) {
        throw std::runtime_error("Failed to read file into contents!\n");
    }

    return contents;
}
