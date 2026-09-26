#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>

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

    std::string path = std::getenv("PATH");

    // Split the PATH variable into individual directories
    std::istringstream pathStream(path);
    std::string directory;
    // while (std::getline(pathStream, directory, ':')) {
    //   std::cout << directory << std::endl;
    // }

    if (program == "exit")
    {
      break;
    }

    if (program == "echo")
    {
      std::cout << argument << std::endl;
    }
    else if (program == "type")
    {
      if (argument == "echo" || argument == "type" || argument == "exit")
      {
        std::cout << argument << " is a shell builtin" << std::endl;
      }
      else
      {
        // std::cout << argument << " not found" << std::endl;
        // Check if the command exists in the PATH directories
        bool commandFound = false;
        while (std::getline(pathStream, directory, ':'))
        {
          std::string commandPath = directory + "/" + argument;
          if (access(commandPath.c_str(), X_OK) == 0)
          {
            std::cout << argument << " is " << commandPath << std::endl;
            commandFound = true;
            break;
          }
        }

        if (!commandFound)
        {
          std::cout << argument << ": not found" << std::endl;
        }
      }
    }
    else
    {
      std::cout << program << ": command not found" << std::endl;
    }
  }
}
