#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>



int mul(int x, int y) { return x * y ;}
void getMulCommands(std::string corrLine)
{
    std::string checkLine = corrLine;


    while(checkLine.size() > 7)
    {
        
        int firstIndex = checkLine.find("mul(" );
        //std::cout << "first index: " << firstIndex << std::endl;
        std::string funCall;

        for(int i = 4; i < 12; i++) //checkmax until if both nums were three digit
        {
            if(checkLine.at(firstIndex + i) == ')')
            {
                funCall = checkLine.substr(firstIndex, i + 1);

                std::cout << "FUNC CALL:" << funCall << std::endl;

                checkLine = checkLine.substr(firstIndex + i + 1);

                //std::cout << "Still need to check: " << checkLine << std::endl;
                
            }

        }
       

    }


   


}
int main()
{
    std::ifstream inputFile("corruptedData.txt");

    if(!inputFile)
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    
    std::string line;

    while(std::getline(inputFile, line))
    {
        //std::cout << line << std::endl;
        getMulCommands(line);
    }

    return 0;
}
