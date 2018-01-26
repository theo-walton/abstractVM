
#include "abstractvm.hpp"

int	main(int ac, char **av)
{
	CommandStack stack;
	
	std::istream *commandStream;
	std::ifstream fileStream;
	
	bool working = true;
	bool filemode = false;


	//combine all potential streams into a generic "commandStream"
	if (ac > 1)
	{
		fileStream.open(av[1]);
		if (fileStream.fail() || !fileStream.good())
		{
			std::cerr << "Error: " << strerror(errno) << std::endl;
			std::exit(1);
		}
		commandStream = &fileStream;
		filemode = true;
	}
	else
	{
		commandStream = &std::cin;
	}
	

	int line = 1;
	
	while (!commandStream->eof())
	{
		std::string input;		
		
		std::getline(*commandStream, input);

		if (!filemode && std::regex_match(input, std::regex(";;.*")))
			break;
		
		try
		{
			stack.executeLine(input);
		}
		catch (std::exception &e)
		{
			working = false;
			Global::errorStream << "Error: Line " << line << ": " <<
				e.what() << "From: " << input << std::endl << std::endl;
		}
		line++;
	}
	if (!stack.shouldExit())
	{
		working = false;
		Global::errorStream << "Fatal Error: no exit condition\n";
	}
	if (working)
	{
		std::cout << Global::outStream.str();
	}
	else
	{
		std::cout << Global::errorStream.str();		
	}
}
