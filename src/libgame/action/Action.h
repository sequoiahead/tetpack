#ifndef ACTION_H_
#define ACTION_H_

class Action {
public:
	explicit Action();
	virtual ~Action();

	virtual void invoke() =0;
};

#endif /* ACTION_H_ */
