#ifndef RESOURCEIMAGE_H_
#define RESOURCEIMAGE_H_

#include <SDL2/SDL_image.h>

#include "libgame/resource/Resource.h"

class ResourceImage : public Resource {
public:
	explicit ResourceImage(const std::string&);
	virtual ~ResourceImage();

	operator SDL_Surface* () const;

protected:
	SDL_Surface* surface;
};

inline ResourceImage::operator SDL_Surface* () const {
	return surface;
}

#endif /* RESOURCEIMAGE_H_ */
