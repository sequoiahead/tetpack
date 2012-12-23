#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>
#include <exception>

class Exception : public std::exception {
public:
	explicit Exception();
	explicit Exception(const std::string&);
	virtual ~Exception() throw();

	virtual const char* what() const throw();

protected:
	std::string cause;
};

inline Exception::Exception()
		: cause("") {
}

inline Exception::Exception(const std::string& aCause)
		: cause(aCause) {
}

inline Exception::~Exception() throw() {
}

inline const char* Exception::what() const throw() {
	return cause.c_str();
}

#endif /* EXCEPTION_H_ */
