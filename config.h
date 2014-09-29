#ifndef CONFIG_H
#define CONFIG_H

// translation language
#define LC_LANG LC_ENGLISH

// program comments
#define COMMENT_STRING LC_COMMENT_STRING
#define COMMENT_PROGRAM_NAME "flappy"
#define COMMENT_VERSION_STRING "0.1"
#define COMMENT_VERSION_NUMBER 0,1,0,0 /* major, minor, revision, subrevision */
#define COMMENT_AUTHORS "nucular"

// platform configuration
#define USE_V200
#define USE_TI92PLUS
#define USE_TI89
#define MIN_AMS 200

// flags and optimization
#define SAVE_SCREEN
#define OPTIMIZE_ROM_CALLS
#define OPTIMIZE_CALC_CONSTS

#endif
