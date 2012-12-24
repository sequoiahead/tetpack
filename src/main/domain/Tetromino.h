#ifndef TETROMINO_H_
#define TETROMINO_H_

enum TetrominoType {
	MINO_I = 0,
	MINO_J,
	MINO_L,
	MINO_O,
	MINO_S,
	MINO_T,
	MINO_Z,
	MINO_LAST
};

class Tetromino {
public:
	virtual ~Tetromino();

	TetrominoType getType() const;

protected:
	explicit Tetromino(TetrominoType);

	TetrominoType type;
};

inline TetrominoType Tetromino::getType() const {
	return type;
}

#endif /* TETROMINO_H_ */
