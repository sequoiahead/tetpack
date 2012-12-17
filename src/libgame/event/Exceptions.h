#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

class NoActionException : public std::exception {
public:
	explicit NoActionException();
};

inline NoActionException::NoActionException()
		: std::exception() {
}

#endif /* NOACTIONEXCEPTION_H_ */
