#include <SDL/SDL_image.h>
#include <algorithm>

#include "libgame/resource/ResourceManager.h"

ResourceManager::ResourceManager(const std::string& aPath)
		: path(aPath) {
	IMG_Init(IMG_INIT_PNG);
}

ResourceManager::~ResourceManager() {
	for (ResourcePoolIt it = pool.begin(); it != pool.end(); it++) {
		delete (*it);
	}
	IMG_Quit();
}

bool ResourceManager::release(Resource* res) {
	ResourcePoolIt it = std::find(pool.begin(), pool.end(), res);
	bool somethingToRelease = pool.end() != it;
	if (somethingToRelease) {
		delete (*it);
	}
	return somethingToRelease;
}
