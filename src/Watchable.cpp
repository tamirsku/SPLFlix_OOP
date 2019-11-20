//
// Created by tamir on 18/11/2019.
//

#include "../include/Watchable.h"
Watchable::Watchable(long id, int length, const std::vector<std::string> &tags):id(id),length(length),tags(tags) { }
std::string Watchable::toString() const { }
Watchable* Watchable::getNextWatchable(Session &) const {}
Watchable::~Watchable() { }

Movie::Movie(long id, const std::string &name, int length, const std::vector<std::string> &tags):Watchable(id,length,tags),name(name) {
}
std::string Movie::toString() const {return "";}
Watchable* Movie::getNextWatchable(Session &) const {  }
void Movie::setNextEpisodeID(long index) {}

Episode::Episode(long id, const std::string &seriesName, int length, int season, int episode,
                 const std::vector<std::string> &tags):Watchable(id,length,tags),seriesName(seriesName),season(season),episode(episode),nextEpisodeId(-1) {}
                 std::string Episode::toString() const { return ""; }
Watchable* Episode::getNextWatchable(Session &) const {}
void Episode::setNextEpisodeID(long index) {nextEpisodeId=index;}