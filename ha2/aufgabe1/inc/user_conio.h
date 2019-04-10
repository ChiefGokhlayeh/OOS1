#ifndef USER_CONIO_H_
#define USER_CONIO_H_

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>

/* Taken from https://stackoverflow.com/a/23035044/4069539 under StackOverflow
 * default MIT license. */

/* NOT PART OF THE EXERCISE! USED ONLY TO ALLOW EASY PORTABILITY TO GCC! */
#define ARROW_UP_KEY ('W')
#define ARROW_LEFT_KEY ('A')
#define ARROW_RIGHT_KEY ('D')
#define ARROW_DOWN_KEY ('S')
#define Q_KEY ('Q')

/* reads from keypress, doesn't echo */
int getch(void);

/* reads from keypress, echoes */
int getche(void);

/**
 Linux (POSIX) implementation of _kbhit().
 Morgan McGuire, morgan@cs.brown.edu
 */
int _kbhit();

#endif
