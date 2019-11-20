//
// Created by tamir on 18/11/2019.
//

#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include "../include/User.h"
#include <fstream>;
#include <iostream>;

using json = nlohmann::json;

void Session::start() {
    std::cout << "SPLFLIX is now on!" << std::endl;
    std::string action;
    while(action!="exit") {
        std::getline(std::cin,action);
        size_t space_pos = action.find(" ");
        std::string subAction;
        if(space_pos!=std::string::npos)
           subAction = action.substr(0,space_pos);
        std::cout << subAction << std::endl;
    }

}

Session::Session(const std::string &configFilePath) {
    std::ifstream i(configFilePath);
    json j;
    i >> j;
    i.close();
    long innerIndex = 0;
    for (auto &element: j["movies"].items()) {
        //    std::cout << innerIndex << element.value()["name"] << element.value()["length"] << std::endl;
        std::vector<std::string> tags;
        for (auto tag: element.value()["tags"].items())
            tags.push_back(tag.value());
        content.push_back(new Movie(innerIndex, element.value()["name"], element.value()["length"], tags));
        //    std::vector<std::string>::iterator iter;
        //   for (iter = tags.begin(); iter < tags.end(); iter++)
        //       std::cout << *iter << std::endl;
        innerIndex++;
    }

    for (auto &element: j["tv_series"].items()) {//for each series
        std::vector<std::string> tagsE;
        for (auto tag: element.value()["tags"].items())
            tagsE.push_back(tag.value());
        std::string seriesName = element.value()["name"];
        int episode_lenght = element.value()["episode_length"];
        int seasonNum = 1;//for each season
        //  int seasonNumber = element.value()["seasons"].
        for (auto season: element.value()["seasons"].items()) {
            for (int i = 1; i <= season.value(); i++) {
                Episode *ep = new Episode(innerIndex, seriesName, episode_lenght, seasonNum, i, tagsE);
                innerIndex++;
                ep->setNextEpisodeID(innerIndex);
                content.push_back(ep);
            }
            seasonNum++;
        }
        content.at(content.size() - 1)->setNextEpisodeID(-1);  //Set the last next episode to be -1
    }
    userMap["default"] = new LengthRecommenderUser("default");
}

Session::~Session() {
//    std::vector< - Not need to delete the content itself
//    for(int i=0;i<content.size();i++)
//        delete content.at(i);
//  Use Iterator: (if needed..)
    for (int i = 0; i < actionsLog.size(); i++)
        delete actionsLog.at(i);
    //Add - Unorderd Map and Something else..

}