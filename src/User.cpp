//
// Created by tamir on 18/11/2019.
//

#include "../include/User.h"
User::User(const std::string &name):name(name) {}
User::User(const User& other): name(other.name),history(other.history) {}
User::~User() {
    history.clear();
}
std::string User::getName() const {return name;}
Watchable* User::getRecommendation(Session &s) {}
std::vector<Watchable*> User::get_history() const {return history;}

LengthRecommenderUser::LengthRecommenderUser(const std::string &name):User(name) {}
Watchable* LengthRecommenderUser::getRecommendation(Session &s) {}

RerunRecommenderUser::RerunRecommenderUser(const std::string &name):User(name) {}
Watchable* RerunRecommenderUser::getRecommendation(Session &s) {}

GenreRecommenderUser::GenreRecommenderUser(const std::string &name):User(name) {}
Watchable* GenreRecommenderUser::getRecommendation(Session &s) {}

