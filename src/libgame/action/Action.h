#ifndef ACTION_H_
#define ACTION_H_

class Action {
public:
	virtual void invoke() =0;
};

template<typename T>
class ActionAbstract : public Action {
public:
	explicit ActionAbstract(T* const);
	virtual ~ActionAbstract();

	virtual void invoke() =0;

protected:
	T* const target;
};

template<typename T>
inline ActionAbstract<T>::ActionAbstract(T* const aTarget)
	: target(aTarget) {
}

template<typename T>
inline ActionAbstract<T>::~ActionAbstract() {
}

template<typename T>
class ActionMethod : public ActionAbstract<T> {
public:
	typedef void (T::*MethodPtr)();

	explicit ActionMethod(T* const, MethodPtr);
	virtual ~ActionMethod();

	virtual void invoke();

protected:
	MethodPtr method;
};

template<typename T>
inline ActionMethod<T>::ActionMethod(T* const aTarget, MethodPtr aPtrMethod)
		: ActionAbstract<T>(aTarget), method(aPtrMethod) {
}

template<typename T>
inline ActionMethod<T>::~ActionMethod() {
}

template<typename T>
inline void ActionMethod<T>::invoke() {
	(this->target->*method)();
}

class ActionFunction : public Action {
	typedef void (*FuncPtr)();

	explicit ActionFunction(FuncPtr);
	virtual ~ActionFunction();

	virtual void invoke();
protected:
	FuncPtr func;
};

inline ActionFunction::ActionFunction(FuncPtr aPtrFunc)
		: func(aPtrFunc) {
}

inline ActionFunction::~ActionFunction() {
}

inline void ActionFunction::invoke() {
	func();
}

#endif /* ACTION_H_ */
