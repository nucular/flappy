#ifndef LOCALE_H
#define LOCALE_H

// translation languages
#define LC_ENGLISH 0
#define LC_GERMAN 1

// default to english
#ifndef LC_LANG
#define LC_LANG LC_ENGLISH
#endif

// translation strings
#if LC_LANG == LC_ENGLISH
	#define LC_COMMENT_STRING "\"Flappy Bird\" clone for TI calculators"

	#define LC_ERROR "ERROR"
	#define LC_GRAYSCALE_ERROR_TEXT "Could not switch to grayscale graphics!"
	#define LC_MEMORY_ERROR_TEXT "Not enough free RAM!"
#elif LC_LANG == LC_GERMAN
	#define LC_COMMENT_STRING "\"Flappy Bird\"-Klon für TI-Rechner"

	#define LC_ERROR "FEHLER"
	#define LC_GRAYSCALE_ERROR_TEXT "Konnte nicht in Graustufen-Modus wechseln!"
	#define LC_MEMORY_ERROR_TEXT "Nicht genug freier Arbeitsspeicher!"
#endif

#endif
