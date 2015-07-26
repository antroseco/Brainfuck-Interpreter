#include "io.hpp"
#include "interpreter.hpp"

#include <iostream>

void Usage()
{
	std::cout << "BRAIN: Brainfuck Interpreter\n\n";
	std::cout << "BRAIN file\n\n";
	std::cout << "\tfile\tSpecifies the Brainfuck source file to execute\n";
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		Usage();
		return EXIT_FAILURE;
	}

	try
	{
		Open(argv[1]);

		while (FileIsGood())
			ProcessCharacter(GetNextInstruction());
	}
	catch (const std::exception& Exception)
	{
		std::cout << Exception.what() << std::endl;
		
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
