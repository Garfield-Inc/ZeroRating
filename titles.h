#ifndef TITLES_H_
    #define TITLES_H_

    #include <algorithm>
    #include <string>
    #include <vector>
    #include <map>

    static std::map<std::string, int> exclusions;
    static std::vector<std::string> titles;

    bool isExclusion(std::string word);

#endif