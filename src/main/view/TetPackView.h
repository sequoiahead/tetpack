#ifndef TETPACKVIEW_H_
#define TETPACKVIEW_H_

#include "view/View.h"

class TetPackView: public View {
public:
	TetPackView();
	virtual ~TetPackView();

	virtual void render();
};

#endif /* TETPACKVIEW_H_ */
