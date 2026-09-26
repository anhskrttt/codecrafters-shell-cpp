#include <iostream>
#include <string>
#include <sstream>

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

    std::istringstream input(command);

    std::string program;
    std::string argument;

    input >> program;
    std::getline(input >> std::ws, argument);

    std::cout << "Program:\t" << program << std::endl;
    std::cout << "Argument:\t" << argument << std::endl;

    if(program == "exit") {
      break;
    }

    if(program == "echo") {
      std::cout << argument << std::endl;
    } else if(program == "type") {
      if(argument == "echo" || argument == "type" || argument == "exit") {
        std::cout << argument << " is a shell builtin" << std::endl;
      } else {
        std::cout << argument << " not found" << std::endl;
      }
    } else {
      std::cout << program << ": command not found" << std::endl;
    }

    //   if (command == "exit")
    //   {
    //     break;
    //   }

    //   else if (command.substr(0, 4) == "echo")
    //   {
    //     // Print the command after echo
    //     std::cout << command.substr(5) << std::endl;
    //   }
    //   else if (command.substr(0, 4) == "type")
    //   {
    //     if (command.substr(5) == "echo" || command.substr(5) == "type" || command.substr(5) == "exit")
    //     {
    //       std::cout << command.substr(5) << " is a shell builtin" << std::endl;
    //     }
    //     else
    //     {
    //       std::cout << command.substr(5) << " not found" << std::endl;
    //     }
    //   }
    //   else
    //   {
    //     // Print the command not found
    //     std::cout << command << ": command not found" << std::endl;
    //   }
  }
}
