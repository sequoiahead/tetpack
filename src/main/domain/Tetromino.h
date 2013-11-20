#ifndef TETROMINO_H_
#define TETROMINO_H_

#include <array>

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

	constexpr static uint8_t MAX = static_cast<int>(_LAST);

	explicit Tetromino(Type);
	virtual ~Tetromino();

	Type getType() const;
	uint8_t getWidth() const;
	uint8_t getHeight() const;

	uint8_t getX() const;
	uint8_t getY() const;

	Direction getDirection() const;

	void rotate(Direction aDir = _DIR_LAST);
	void move(uint8_t, uint8_t);

private:
	Type type;
	Direction dir;

	constexpr static std::array<std::pair<uint8_t,uint8_t>,MAX> dimensions{{{4,1},{2,4},{2,4},{2,2},{3,2},{3,2},{3,2}}};

	uint8_t w; //in blocks
	uint8_t h; //in blocks
	uint8_t x = 0; //in blocks
	uint8_t y = 0; //in blocks
};

inline Tetromino::Type Tetromino::getType() const {
	return type;
}

inline uint8_t Tetromino::getWidth() const {
	return w;
}

inline uint8_t Tetromino::getHeight() const {
	return h;
}

inline uint8_t Tetromino::getX() const {
	return x;
}

inline uint8_t Tetromino::getY() const {
	return y;
}

inline Tetromino::Direction Tetromino::getDirection() const {
	return dir;
}

#endif /* TETROMINO_H_ */
