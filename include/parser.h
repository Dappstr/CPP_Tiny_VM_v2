#pragma once

#include <vector>
#include "tokenize.h"

struct Binding {
    std::string id;
    int value;
};

void parse(std::vector<Token>&& tokens, std::vector<Binding>& binds, std::vector<int>& stack);
