//
// Created by tamir on 18/11/2019.
//

#include "../include/Action.h"
BaseAction::BaseAction() {}
ActionStatus BaseAction::getStatus() const {return status;}
void BaseAction::act(Session &sess) {}
std::string BaseAction::toString() const {}
void BaseAction::complete() {status = COMPLETED;}
void BaseAction::error(const std::string &errorMsg) {status = ERROR; BaseAction::errorMsg = errorMsg;}
std::string BaseAction::getErrorMsg() const {return errorMsg;}
BaseAction::~BaseAction() {}

void CreateUser::act(Session &sess) {}
std::string CreateUser::toString() const {}

void ChangeActiveUser::act(Session &sess) {}
std::string ChangeActiveUser::toString() const {}

void DeleteUser::act(Session &sess) { }
std::string DeleteUser::toString() const {}

void DuplicateUser::act(Session &sess) {}
std::string DuplicateUser::toString() const {}

void PrintContentList::act(Session &sess) {}
std::string PrintContentList::toString() const {}

void PrintWatchHistory::act(Session &sess) {}
std::string PrintWatchHistory::toString() const {}

void Watch::act(Session &sess) {}
std::string Watch::toString() const {}

void PrintActionsLog::act(Session &sess) {}
std::string PrintActionsLog::toString() const {}

void Exit::act(Session &sess) {}
std::string Exit::toString() const {}


