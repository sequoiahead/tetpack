#ifndef TETROMINO_H_
#define TETROMINO_H_

#include <list>

class Tetromino {
public:
	enum Type {
		I = 0,
		J,
		L,
		O,
		S,
		T,
		Z,
		_LAST
	};

	enum Direction {
		DIR_UP = 0,
		DIR_RIGHT,
		DIR_DOWN,
		DIR_LEFT,
		_DIR_LAST
	};

	explicit Tetromino(Type);
	virtual ~Tetromino();

	Type getType() const;
	void rotate();

	void reset();

private:
	Type type;
	Direction dir;
};

inline Tetromino::Type Tetromino::getType() const {
	return type;
}

#endif /* TETROMINO_H_ */
