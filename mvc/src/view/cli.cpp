#include <vector>
#include <iostream>

std::string Cli::getInput(std::string line)
{
	this->print(line);
	std::string input;
	getline(std::cin, input);
	return input;
}


void Cli::print(std::string line)
{
	std::cout << line << std::endl;
}

// void Cli::start()
// {
// 	DB<Dna*>* dnaDB = new DB<Dna*>();

// 	ICommand *pCommand = NULL;
// 	std::string line;

// 	while (pCommand == NULL)
// 	{
// 		std::cout << "\n> cmd >>> ";
// 		getline(std::cin, line);

// 		if( line == "q" )
//         break;

//     	std::string commandName = Parser::getMethod(line);
// 		std::vector<std::string> params = Parser::getParams(line);

// 		ICommand *pCommand = CommandFactory::CreateCommand(commandName);
//         if( pCommand )
//         {
//             pCommand->validateParams(params);
//             Dna* dna = pCommand->execute(params);
//             if ( dna )
//             	dnaDB->append(dna->getName(), dna->getId(), dna);
//         }
//         else
//         {
//             std::cout << "That command doesn’t exist! Choose another!" << std::endl;
//         }
//         pCommand = NULL;

// 		Dna* someone = dnaDB->getItem("seq1");
// 		if (someone)
// 			std::cout << someone->getDnaString() << std::endl;

// 	}
// }