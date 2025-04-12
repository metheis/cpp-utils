# cpp-utils
A repository of general use simple C++ utilities.

## About this project.

As many C/C++ developers are aware, code compile time is an important consideration as projects grow in scope and size. And as many others know, one of the most prolific methods to increasing compile time is importing code. Specifically, importing code that you did not write (such as from standard libraries or other dependencies). Not to mention the bug and security liabilities that poses. For example, [including the `memory` standard library](https://godbolt.org/z/b7Kr6dsqW), adds 28 thousand lines of code to your program!

I've noticed an increasing presence of custom implementations of core utilities across different open source projects I follow. That, along with my own experience in industry, has motivated me to develop an open source repository of general use C++ utilities. The general project goals are:

1. Provide helpful functionality that makes writing C++ programs easier (eg. core types, finding elements in an array, etc.).
2. Limit the use of the C++ standard library or other dependencies.
3. It should compile quickly (that's why we're here, right?).
4. Follow safe coding principles (eg. noexcept / no throws).

