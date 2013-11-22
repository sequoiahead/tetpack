#ifndef SIGNAL_H_
#define SIGNAL_H_

#include "libgame/3rdparty/nano_signal_slot.hpp"


template <typename Re_t>
using Signal = Nano::signal<Re_t>;

#endif /* SIGNAL_H_ */
