#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <cstdlib>
#include <ctime>

#include <libgame/event/Signal.h>

#include "domain/Tetromino.h"

class GameBoard {
public:
	GameBoard();
	~GameBoard();

	const Tetromino& getCurrentMino() const;
	const Tetromino& getNextMino() const;

	void rotate();
	void left();
	void right();
	void drop();
private:
	Tetromino* minos[Tetromino::_LAST];
	Tetromino::Type currentMino;
	Tetromino::Type nextMino;

	Tetromino& getCurrentMino();
	Tetromino::Type randomMino();

	//noncopyable
	GameBoard(const GameBoard&);
	const GameBoard& operator=(const GameBoard&);
};

inline Tetromino& GameBoard::getCurrentMino() {
	return *minos[currentMino];
}

inline const Tetromino& GameBoard::getCurrentMino() const {
	return *minos[currentMino];
}

inline const Tetromino& GameBoard::getNextMino() const {
	return *minos[nextMino];
}

#endif /* GAMEBOARD_H_ */
