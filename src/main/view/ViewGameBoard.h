#ifndef VIEWGAMEBOARD_H_
#define VIEWGAMEBOARD_H_

#include <libgame/view/ViewScreen.h>
#include <libgame/resource/ResourceImage.h>
#include <libgame/resource/ResourceManager.h>

#include "domain/GameBoard.h"

#include <SDL2/SDL_image.h>

class ViewGameBoard : public ViewScreen {
public:
	explicit ViewGameBoard(ResourceManager<ResourceImage>*, const Well*);
	virtual ~ViewGameBoard();

protected:
	virtual void prepareScreen(unsigned int);

private:
	ResourceManager<ResourceImage>* imgMan;
	const Well* well;
	ResourceImage* minos[Tetromino::_LAST];
	const char* minosImgs[Tetromino::_LAST];

	//noncopyable
	ViewGameBoard(const ViewGameBoard&);
	const ViewGameBoard& operator=(const ViewGameBoard&);
};

#endif /* VIEWGAMEBOARD_H_ */
