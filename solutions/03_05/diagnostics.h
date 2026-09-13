#ifndef CPP_LEARNING_LAB_DIAGNOSTICS_H
#define CPP_LEARNING_LAB_DIAGNOSTICS_H

#include <iostream>

#ifdef ENABLE_DIAGNOSTICS
#define LAB_LOG(message) (std::clog << message << '\n')
#else
#define LAB_LOG(message) ((void)0)
#endif

#endif
