#ifndef ACTIONLOGGING_H_
#define ACTIONLOGGING_H_

#include "libgame/action/Action.h"

class ActionLogging : public ActionAbstract<const char> {
public:
	explicit ActionLogging(const char*);
	virtual ~ActionLogging();

	virtual void invoke();
};

#endif /* ACTIONLOGGING_H_ */
