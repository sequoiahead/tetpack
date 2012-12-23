#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <string>
#include <iostream>

enum ResourceType {
	IMAGE = 0,
	LAST
};

typedef unsigned int ResourceId;

class Resource {
public:
	explicit Resource(const std::string&, ResourceType);
	virtual ~Resource();

protected:
	std::string url;
	ResourceType type;
};

inline Resource::Resource(const std::string& aUrl, ResourceType aType)
		: url(aUrl), type(aType) {
}

inline Resource::~Resource() {
	std::cout << url << " destructed" << std::endl;
}

#endif /* RESOURCE_H_ */
