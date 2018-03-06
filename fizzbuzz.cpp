// fizzbuzz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/* stdafx does not allow io by default.  Edited it to allow IO and strings. */
//
/* Comment style, using bracketed comments for a potentially multi line paragraph
regardless of whether it is actually multi line.  Using line comments between
paragraphs and for terse standard comments. */
//
/* Comment style, using paragraphs and punctuation for non terse comments. */
//
int main()
{
	/* testing C++17 initialization */
	for (int m{ 1 }; m <= 100; m++) {
		bool DivisibleByThree{ !(m % 3) };
		bool DivisibleByFive{ !(m % 5) };
		if (DivisibleByThree) {
			std::cout << "fizz ";
		}
		/* Brace style forced by Visual Studio default. */
		if (DivisibleByFive) {
			std::cout << "buzz ";
		}
		if (!DivisibleByFive && !DivisibleByThree) {
			std::cout << m;
		}
		std::cout << "\n";
	}
	const std::string hello{ "hello" };
	const std::string world{ "world" };
	std::cout << hello + " " + world << std::endl;  /* std::endl outputs a \n
													and also flushes the buffer */
													/* Which is why \n inside loop, but std::endl at completion of program */
													//
													/* This flush is probably redundant, because the environment is going to
													perform a get character  on program completion, which will force a flush
													but inside the loop, a flush would definitely be redundant and possibly
													harmful. */
													//
	//clear buffer, wait for input to close program
	std::cin.clear(); std::cin.ignore(INT_MAX, '\n');
	//std::cin.get();
	return 0;
}

