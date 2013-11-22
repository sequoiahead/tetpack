#ifndef VIEWGAMEBOARD_H_
#define VIEWGAMEBOARD_H_

#include <libgame/view/ViewScreen.h>
#include <libgame/resource/ResourceImage.h>
#include <libgame/resource/ResourceManager.h>

#include "domain/GameBoard.h"

class ViewGameBoard : public ViewScreen {
public:
	explicit ViewGameBoard(ResourceManager<ResourceImage>*, const Well*);
	virtual ~ViewGameBoard();
	ViewGameBoard(const ViewGameBoard&) = delete;
	const ViewGameBoard& operator=(const ViewGameBoard&) = delete;

protected:
	virtual void prepareScreen(unsigned int);

private:
	ResourceManager<ResourceImage>* imgMan;
	const Well* well;
	SDL_Texture* minos[Tetromino::_LAST];
	const char* minosUrls[Tetromino::_LAST];

	uint8_t blockWidthPx;
	uint8_t blockHeightPx;
};

#endif /* VIEWGAMEBOARD_H_ */
