#include <string>

#include "libgame/core/Exception.h"

#ifndef RESOURCEEXCEPTIONS_H_
#define RESOURCEEXCEPTIONS_H_

class ResourceException: public Exception {
public:
	explicit ResourceException(const std::string&);
	explicit ResourceException(const std::string&, const std::string&);
	virtual ~ResourceException() throw ();

protected:
	const std::string& url;
};

inline ResourceException::ResourceException(const std::string& aUrl)
		: url(aUrl) {
}

inline ResourceException::ResourceException(const std::string& aUrl, const std::string& aDetails)
		: Exception(aDetails), url(aUrl) {
}

inline ResourceException::~ResourceException() throw () {
}

#endif /* RESOURCEEXCEPTIONS_H_ */
