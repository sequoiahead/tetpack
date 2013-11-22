#include <SDL2/SDL_video.h>

#include "libgame/resource/ResourceImage.h"
#include "libgame/resource/ResourceExceptions.h"

ResourceImage::ResourceImage(const std::string& aUrl)
		: Resource(aUrl, RES_IMAGE) {
	surface = IMG_Load(aUrl.c_str());
	if (NULL == surface) {
		ResourceException e(aUrl, IMG_GetError());
		throw e;
	}
}

ResourceImage::~ResourceImage() {
	SDL_FreeSurface(surface);
}
