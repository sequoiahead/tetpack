#ifndef TETPACKVIEW_H_
#define TETPACKVIEW_H_

#include <libgame/view/ViewScreen.h>
#include <libgame/resource/ResourceImage.h>
#include <libgame/resource/ResourceManager.h>

#include <SDL/SDL_image.h>

class TetPackView : public ViewScreen {
public:
	explicit TetPackView(ResourceManager&);
	virtual ~TetPackView();

protected:
	virtual void prepareScreen(unsigned int);

private:
	ResourceManager resMan;
	ResourceImage* lMino;
};

#endif /* TETPACKVIEW_H_ */
