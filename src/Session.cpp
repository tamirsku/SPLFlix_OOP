//
// Created by tamir on 18/11/2019.
//

#include "../include/Session.h"
#include "../include/json.hpp"
#include <fstream>;
#include <iostream>;
using json = nlohmann::json;
void Session::start() {
    std::cout << "SPLFLIX is now on!" << std::endl;
}
Session::Session(const std::string &configFilePath) {
//    std::ifstream i(configFilePath);
//    json j;
//    i >> j;
//    std::cout << j["movies"];


}
Session::~Session() {
//    std::vector< - Not need to delete the content itself
//    for(int i=0;i<content.size();i++)
//        delete content.at(i);
//  Use Iterator: (if needed..)
    for(int i=0;i<actionsLog.size();i++)
        delete actionsLog.at(i);
    //Add - Unorderd Map and Something else..

}