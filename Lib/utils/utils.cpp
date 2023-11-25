#include <regex>
#include "utils.h"

bool isNumber(const std::string &s) {
    std::regex numberRegex("^[-+]?[0-9]*\\.?[0-9]+$");
    return std::regex_match(s, numberRegex);
}