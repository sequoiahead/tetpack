#ifndef TETPACKVIEW_H_
#define TETPACKVIEW_H_

#include <libgame/view/ViewScreen.h>
#include <libgame/resource/ResourceImage.h>
#include <libgame/resource/ResourceManager.h>

#include "domain/GameBoard.h"

#include <SDL/SDL_image.h>

class ViewGameBoard : public ViewScreen {
public:
	explicit ViewGameBoard(ResourceManager<ResourceImage>*, const GameBoard*);
	virtual ~ViewGameBoard();

protected:
	virtual void prepareScreen(unsigned int);

private:
	ResourceManager<ResourceImage>* imgMan;
	const GameBoard* board;
	ResourceImage* minos[Tetromino::_LAST];
	const char* minosImgs[Tetromino::_LAST];

	//noncopyable
	ViewGameBoard(const ViewGameBoard&);
	const ViewGameBoard& operator=(const ViewGameBoard&);
};

#endif /* TETPACKVIEW_H_ */
