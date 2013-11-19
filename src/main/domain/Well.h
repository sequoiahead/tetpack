#ifndef WELL_H_
#define WELL_H_

#include <iostream>
#include <SDL2/SDL_events.h>
#include <libgame/event/Signal.h>

#include "domain/TetrominoFactory.h"

class Well {
public:
	explicit Well(TetrominoFactory*);
	~Well();

	const Tetromino& getCurrentMino() const;

	const Signal<void()>& onDrop() const;
	const Signal<void()>& onHitGround() const;
	const Signal<void()>& onHitWall() const;
	const Signal<void()>& onLineBurned() const;
	const Signal<void()>& onMove() const;
	const Signal<void()>& onNextRound() const;
	const Signal<void()>& onRotate() const;
	const Signal<void()>& onStuck() const;

	void rotate(SDL_Event&);
	void left(SDL_Event&);
	void right(SDL_Event&);
	void drop(SDL_Event&);

private:
	Signal<void()> signalLineBurned;
	Signal<void()> signalStuck;
	Signal<void()> signalRotate;
	Signal<void()> signalMove;
	Signal<void()> signalDrop;
	Signal<void()> signalHitGround;
	Signal<void()> signalHitWall;
	Signal<void()> signalNextRound;
	TetrominoFactory* factoryNextMino;
	Tetromino mino;

	void nextRound();
};

inline const Tetromino& Well::getCurrentMino() const {
	return mino;
}

inline const Signal<void()>& Well::onDrop() const {
	return signalDrop;
}

inline const Signal<void()>& Well::onHitGround() const {
	return signalHitGround;
}

inline const Signal<void()>& Well::onHitWall() const {
	return signalHitWall;
}

inline const Signal<void()>& Well::onLineBurned() const {
	return signalLineBurned;
}

inline const Signal<void()>& Well::onMove() const {
	return signalMove;
}

inline const Signal<void()>& Well::onNextRound() const {
	return signalNextRound;
}

inline const Signal<void()>& Well::onRotate() const {
	return signalRotate;
}

inline const Signal<void()>& Well::onStuck() const {
	return signalStuck;
}

#endif /* WELL_H_ */
