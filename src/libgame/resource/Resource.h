#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <string>

enum ResourceType {
	RES_IMAGE = 0,
	RES_LAST
};

typedef unsigned int ResourceId;

class Resource {
public:
	explicit Resource(const std::string&, ResourceType);
	virtual ~Resource();

	const std::string& getUrl() const;

	bool operator==(const Resource&) const;
	bool operator==(const Resource*) const;

protected:
	std::string url;
	ResourceType type;
};

inline Resource::Resource(const std::string& aUrl, ResourceType aType)
		: url(aUrl), type(aType) {
}

inline Resource::~Resource() {
}

inline const std::string& Resource::getUrl() const {
	return url;
}

inline bool Resource::operator ==(const Resource& aRes) const {
	return url == aRes.url;
}

inline bool Resource::operator ==(const Resource* aRes) const {
	return url == aRes->url;
}

#endif /* RESOURCE_H_ */
