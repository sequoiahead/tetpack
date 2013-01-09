#ifndef ACTIONLOGGING_H_
#define ACTIONLOGGING_H_

#include "libgame/action/Action.h"

class ActionLogging : public Action {
public:
	explicit ActionLogging(const char*);
	virtual ~ActionLogging();

	virtual void invoke();
private:
	const char* msg;
};

#endif /* ACTIONLOGGING_H_ */
