#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <cstdlib>
#include <ctime>

#include "domain/Tetromino.h"
#include "domain/TetrominoFactory.h"
#include "domain/Well.h"

class GameBoard : public TetrominoFactory {
public:
	GameBoard();
	~GameBoard();

	const Well& getWell() const;

	virtual Tetromino& getMino();

private:
	Tetromino* minos[Tetromino::_LAST];
	Well* well;
	Tetromino::Type currentMino;
	Tetromino::Type nextMino;

	Tetromino& getCurrentMino();
	Tetromino& getNextMino();
	Tetromino::Type randomMino();

	//noncopyable
	GameBoard(const GameBoard&);
	const GameBoard& operator=(const GameBoard&);
};

inline Tetromino& GameBoard::getMino() {
	currentMino = nextMino;
	nextMino = randomMino();
	return *minos[currentMino];
}

inline Tetromino& GameBoard::getCurrentMino() {
	return *minos[currentMino];
}

inline Tetromino& GameBoard::getNextMino() {
	return *minos[nextMino];
}

inline const Well& GameBoard::getWell() const {
	return *well;
}

#endif /* GAMEBOARD_H_ */
