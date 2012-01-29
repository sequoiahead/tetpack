#ifndef COMMAND_H_
#define COMMAND_H_

class Command {
public:

	static const int CMD_NONE;
	static const int CMD_EXIT;

	explicit Command(int aId)
			: id(aId) {
	}

	inline const int& getId() const {
		return id;
	}

	inline bool operator==(const Command& cmd) const {
		return id == cmd.id;
	}

	inline bool operator!=(const Command& cmd) const {
		return !(*this == cmd);
	}

	virtual ~Command() {
	}
private:
	int id;
};

class CommandNone : public Command {
public:
	CommandNone()
		: Command(Command::CMD_NONE) {
	};
};

class CommandExit : public Command {
public:
	CommandExit()
		: Command(Command::CMD_EXIT) {
	};
};

#endif /* COMMAND_H_ */
