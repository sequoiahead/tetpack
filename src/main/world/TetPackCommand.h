#ifndef TETPACKCOMMAND_H_
#define TETPACKCOMMAND_H_

class CommandMoveRight : public Command<TetPackWorld> {
public:
	CommandMoveRight()
			: Command(1) {
	}
};

class CommandMoveLeft : public Command<TetPackWorld> {
public:
	CommandMoveLeft()
			: Command(2) {
	}
};

class CommandRotate : public Command<TetPackWorld> {
public:
	CommandRotate()
			: Command(3) {
	}
};

class CommandDrop : public Command<TetPackWorld> {
public:
	CommandDrop()
			: Command(4) {
	}
};

#endif /* TETPACKCOMMAND_H_ */
