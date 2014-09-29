flappy()
========

This C project aims to recreate the "Flappy Bird" mobile game by Dong Nguyen
on TI calculators, using the TIGCC compiler and the extgraph library for fast
drawing operations.

Building
--------

To build flappy(), you need [TIGCC](http://tigcc.ticalc.org) and if you're on
Windows Vista/7 the [GCC fix](http://tigcc.org/gcc/gcc-4.1.2-tigcc-pre10-win32-gcc-exe.7z).
After you've added the folder with the tigcc executable to your PATH, you can
either run [inmake](https://github.com/boxmein/inmake) on flappy.c or compile
manually:
```
tigcc -O2 -Wall flappy.c extgraph/extgraph.a
```

You can switch between the localizations by passing `-DLC_LANG=[language]` as an
argument. Currently `LC_ENGLISH` and `LC_GERMAN` are supported in place of
`[language]`.
