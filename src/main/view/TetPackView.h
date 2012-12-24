#ifndef TETPACKVIEW_H_
#define TETPACKVIEW_H_

#include <libgame/view/ViewScreen.h>
#include <libgame/resource/ResourceImage.h>
#include <libgame/resource/ResourceManager.h>

#include "domain/GameBoard.h"
#include "domain/Tetromino.h"

#include <SDL/SDL_image.h>

class TetPackView : public ViewScreen {
public:
	explicit TetPackView(ResourceManager<ResourceImage>*, GameBoard*);
	virtual ~TetPackView();

protected:
	virtual void prepareScreen(unsigned int);

private:
	ResourceManager<ResourceImage>* imgMan;
	GameBoard* board;
	ResourceImage* minos[MINO_LAST];

	const char * minosImgs[MINO_LAST];

	//noncopyable
	TetPackView(const TetPackView&);
	const TetPackView& operator=(const TetPackView&);
};

#endif /* TETPACKVIEW_H_ */
