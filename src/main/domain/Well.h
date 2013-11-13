#ifndef WELL_H_
#define WELL_H_

#include <iostream>
#include <libgame/event/Signal.h>

#include "domain/TetrominoFactory.h"

class Well {
public:
	explicit Well(TetrominoFactory*);
	~Well();

	const Tetromino& getCurrentMino() const;

	const Signal& onDrop() const;
	const Signal& onHitGround() const;
	const Signal& onHitWall() const;
	const Signal& onLineBurned() const;
	const Signal& onMove() const;
	const Signal& onNextRound() const;
	const Signal& onRotate() const;
	const Signal& onStuck() const;

	void rotate();
	void left();
	void right();
	void drop();

private:
	Signal signalLineBurned;
	Signal signalStuck;
	Signal signalRotate;
	Signal signalMove;
	Signal signalDrop;
	Signal signalHitGround;
	Signal signalHitWall;
	Signal signalNextRound;
	TetrominoFactory* factoryNextMino;
	Tetromino mino;

	void nextRound();
};

inline const Tetromino& Well::getCurrentMino() const {
	return mino;
}

inline const Signal& Well::onDrop() const {
	return signalDrop;
}

inline const Signal& Well::onHitGround() const {
	return signalHitGround;
}

inline const Signal& Well::onHitWall() const {
	return signalHitWall;
}

inline const Signal& Well::onLineBurned() const {
	return signalLineBurned;
}

inline const Signal& Well::onMove() const {
	return signalMove;
}

inline const Signal& Well::onNextRound() const {
	return signalNextRound;
}

inline const Signal& Well::onRotate() const {
	return signalRotate;
}

inline const Signal& Well::onStuck() const {
	return signalStuck;
}

#endif /* WELL_H_ */
