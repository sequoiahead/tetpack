#ifndef COMMAND_H_
#define COMMAND_H_

typedef unsigned int CommandId;

template <class W>
class Command {
public:

	explicit Command(CommandId);
	virtual ~Command();
	const int& getId() const;
	virtual void execute(W&) const =0;

	inline bool operator==(const Command& cmd) const {
		return id == cmd.id;
	}

	inline bool operator!=(const Command& cmd) const {
		return !(*this == cmd);
	}

private:
	CommandId id;
};

template<class W>
Command<W>::Command(CommandId aId)
		: id(aId) {
}

template<class W>
inline const int& Command<W>::getId() const {
	return id;
}

#endif /* COMMAND_H_ */
