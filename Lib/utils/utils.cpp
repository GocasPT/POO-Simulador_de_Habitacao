#include <regex>
#include "utils.h"

using std::regex;

bool isNumber(const string &s) {
    regex numberRegex("^[-+]?[0-9]*\\.?[0-9]+$");
    return regex_match(s, numberRegex);
}