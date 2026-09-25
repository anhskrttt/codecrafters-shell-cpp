#include <iostream>
#include <string>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true)
  {
    // TODO: Uncomment the code below to pass the first stage
    std::cout << "$ ";

    // Read user input
    std::string command;
    std::getline(std::cin, command);

    if (command == "exit")
    {
      break;
    }
    else if (command.substr(0, 4) == "echo")
    {
      // Print the command after echo
      std::cout << command.substr(5) << std::endl;
    }
    else if (command.substr(0, 4) == "type")
    {
      if (command.substr(5) == "echo" || command.substr(5) == "type" || command.substr(5) == "exit")
      {
        std::cout << command.substr(5) << " is a shell builtin" << std::endl;
      }
      else
      {
        std::cout << command.substr(5) << " not found" << std::endl;
      }
    }
    else
    {
      // Print the command not found
      std::cout << command << ": command not found" << std::endl;
    }
  }
}
