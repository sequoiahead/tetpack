#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <string>
#include <list>

#include "libgame/resource/Resource.h"

class ResourceManager {
public:
	explicit ResourceManager(const std::string&);
	virtual ~ResourceManager();

	template<typename ResourceType>
	ResourceType* get(const std::string&);

	bool release(Resource*);

private:
	typedef std::list<Resource*> ResourcePool;
	typedef ResourcePool::iterator ResourcePoolIt;

	ResourcePool pool;
	std::string path;
};

template<typename ResourceType>
inline ResourceType* ResourceManager::get(const std::string& url) {
	std::string realPath = path;
	realPath.append(url);

	ResourceType* res = new ResourceType(realPath);
	pool.push_back(res);
	return res;
}

#endif /* RESOURCEMANAGER_H_ */
