#pragma once
#include <functional>
#include <map>
#include <list>

struct Observer
{
	std::function<void()> callback;
	std::string message;
	std::string name;
};

class ObserverCenter
{
public:
	void addObserver(const std::string&, const std::string&, std::function<void()>);
	bool removeObserver(const std::string&, const std::string&);
	void postNotification(const std::string&);
private:
	std::map<std::string, std::list<Observer>> observers;
};



