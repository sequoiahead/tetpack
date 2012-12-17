#ifndef TETPACKVIEW_H_
#define TETPACKVIEW_H_

#include <libgame/view/ViewScreen.h>

class TetPackView: public ViewScreen {
public:
	TetPackView();
	virtual ~TetPackView();

	virtual void render();
};

#endif /* TETPACKVIEW_H_ */
