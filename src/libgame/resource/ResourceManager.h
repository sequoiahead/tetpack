#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <string>
#include <map>

#include "libgame/resource/Resource.h"

template<typename ResourceType>
class ResourceManager {
public:
	explicit ResourceManager(const std::string&);
	virtual ~ResourceManager();

	ResourceType* get(const std::string&, bool = true);

	bool release(Resource*);
protected:
	ResourceType* load(const std::string&);

private:
	typedef std::map<std::string, ResourceType*> ResourcePool;
	typedef typename ResourcePool::iterator ResourcePoolIt;

	ResourcePool pool;
	std::string path;

	//noncopyable
	ResourceManager(const ResourceManager&);
	const ResourceManager operator=(const ResourceManager&);
};

template<typename ResourceType>
inline ResourceType* ResourceManager<ResourceType>::get(const std::string& aUrl, bool returnFromCache) {
	if (returnFromCache) {
		ResourcePoolIt it = pool.find(aUrl);
		if (pool.end() != it) {
			return it->second;
		}
	}
	return pool[aUrl] = load(aUrl);
}

template<typename ResourceType>
inline ResourceType* ResourceManager<ResourceType>::load(const std::string& aUrl) {
	std::string realPath = path;
	realPath.append(aUrl);

	return new ResourceType(realPath);
}

template<typename ResourceType>
ResourceManager<ResourceType>::ResourceManager(const std::string& aPath)
		: path(aPath) {
	IMG_Init(IMG_INIT_PNG);
}

template<typename ResourceType>
ResourceManager<ResourceType>::~ResourceManager() {
	for (ResourcePoolIt it = pool.begin(); it != pool.end(); it++) {
		delete it->second;
	}
	IMG_Quit();
}
template<typename ResourceType>
bool ResourceManager<ResourceType>::release(Resource* res) {
	ResourcePoolIt toDelete = pool.find(res->getUrl());
	bool somethingToRelease = pool.end() != toDelete;
	if (somethingToRelease) {
		delete toDelete->second;
	}
	return somethingToRelease;
}


#endif /* RESOURCEMANAGER_H_ */
