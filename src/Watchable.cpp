//
// Created by tamir on 18/11/2019.
//

#include "../include/Watchable.h"
Watchable::Watchable(long id, int length, const std::vector<std::string> &tags):id(id),length(length),tags(tags) { }
std::string Watchable::toString() const { }
Watchable* Watchable::getNextWatchable(Session &) const {}
Watchable::~Watchable() { }
Watchable* Watchable::clone() {}

Movie::Movie(long id, const std::string &name, int length, const std::vector<std::string> &tags):Watchable(id,length,tags),name(name) {
}
std::string Movie::toString() const {return "";}
Watchable* Movie::getNextWatchable(Session &) const {  }
Movie*  Movie::clone() {
    return new Movie(*this);
}

Episode::Episode(long id, const std::string &seriesName, int length, int season, int episode,
                 const std::vector<std::string> &tags):Watchable(id,length,tags),seriesName(seriesName),season(season),episode(episode),nextEpisodeId(-1) {}
std::string Episode::toString() const { return ""; }
Watchable* Episode::getNextWatchable(Session &) const {}
Episode* Episode::clone() {
    return new Episode(*this);}