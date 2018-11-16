#ifndef CLEAR_H
#define CLEAR_H

#ifdef __unix__
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif

#endif // !CLEAR_H
