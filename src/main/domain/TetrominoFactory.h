#ifndef TETROMINOFACTORY_H_
#define TETROMINOFACTORY_H_

#include "domain/Tetromino.h"

class TetrominoFactory {
public:
	virtual ~TetrominoFactory();
	virtual Tetromino& getMino() = 0;
};

inline TetrominoFactory::~TetrominoFactory() {
}

#endif /* TETROMINOFACTORY_H_ */
