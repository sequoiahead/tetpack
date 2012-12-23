#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include "libgame/core/Exception.h"

class NoActionException : public Exception {
public:
	explicit NoActionException();
	explicit NoActionException(const char*);
};

inline NoActionException::NoActionException()
		: Exception() {
}

inline NoActionException::NoActionException(const char* cause)
		: Exception(cause) {
}

#endif /* NOACTIONEXCEPTION_H_ */
