#include "ObserverCenter.h"
#include <iostream>

void ObserverCenter::addObserver(const std::string& name, const std::string& message, std::function<void()> callback  ){
	Observer obs;
	obs.callback = callback;
	obs.message = message;
	obs.name = name;
	observers[message].push_back(obs);
}

bool ObserverCenter::removeObserver(const std::string& _name, const::std::string& _message)
{
    std::list<Observer> &list = observers[_message];
    std::list<Observer>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        if (it->name == _name) {
			list.erase(it);
            return true;
        }
    }
    return false;
}



void ObserverCenter::postNotification(const std::string& _message)
{
	std::list<Observer> &list = observers[_message];
	std::list<Observer>::iterator it;
	for (it = list.begin(); it != list.end(); it++) {
		if(it->message == _message)
		{
			it->callback();
		}
	}
}