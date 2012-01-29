#ifndef TETPACKCOMMAND_H_
#define TETPACKCOMMAND_H_

class CommandMoveRight : public Command {
public:
	CommandMoveRight()
			: Command(1) {
	}
};

class CommandMoveLeft : public Command {
public:
	CommandMoveLeft()
			: Command(2) {
	}
};

class CommandRotate : public Command {
public:
	CommandRotate()
			: Command(3) {
	}
};

class CommandDrop : public Command {
public:
	CommandDrop()
			: Command(4) {
	}
};

#endif /* TETPACKCOMMAND_H_ */
