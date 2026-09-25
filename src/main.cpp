#include <iostream>
#include <string>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // TODO: Uncomment the code below to pass the first stage
  std::cout << "$ ";

  // Read user input
  std::string command;
  std::getline(std::cin, command);

  // Print the command not found
  std::cout << command << ": command not found" << std::endl;
}
