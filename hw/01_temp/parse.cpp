
#include <string>
#include <regex>
#include <vector>
#include "parse.hpp"

config_t getConfig(std::string text){
    config_t config;
    std::regex regexConfig("(\\w+).(\\w+)=([\\w-]+)");
    std::smatch fn_match;
    config.valid = false;

    if(std::regex_search(text, fn_match, regexConfig)){
        if(fn_match[1].compare("config") == 0){
            config.type = fn_match[2];
            config.value = fn_match[3];
            config.valid = true;
        }
        else{
            config.type = "not config";
        }
    }
    return config;
}

sum_t getSum(std::string text, std::vector<int> numbers){
    sum_t sum;
    std::regex regexConfig("(\\w+)\\((\\w):(\\w)\\)");
    std::smatch fn_match;
    sum.valid = false;
    sum.value = 0;

    if(std::regex_search(text, fn_match, regexConfig)){
        if(fn_match[1].compare("SUM") == 0){
            std::string temp = fn_match[2];
            int from = temp[0] - 'A';
            temp = fn_match[3];
            int to = temp[0] - 'A';

            if(to < (int)numbers.size()){
                for(int i=from; i<=to; i++){
                    sum.value += numbers[i];
                }
                sum.valid = true;
                sum.width = std::to_string(sum.value).size();
            }
            else{
                sum.valid = false;
            }
        }
    }
    return sum;
}
