#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>



int mul(int x, int y) { return x * y ;}

int convertandCallFunc(std::string* funcCall)
{
    int x, y;
    std::string sx,sy;
    int CommaIndex = 0;
    int product; 
    int startingIndex = 4; 

    for(int i = 4; i < 8; i++)
    {
        if(funcCall->at(i) == ',')
        {
            //std::cout << "found comman at " << i << std::endl;
            CommaIndex = i;
            sx = funcCall->substr(startingIndex, CommaIndex - startingIndex);
            break;
        }
        else
        {
            sx = funcCall->substr(4, i + 1);

        }
 
    }

    for(int i = CommaIndex + 1; i < funcCall->size(); i++)
    {
        if(funcCall->at(i) == ')')
        {
            //std::cout << "FOund ending at "<< i << std::endl;
            sy = funcCall->substr(CommaIndex + 1, i - (CommaIndex + 1));
            break;
        }
        else
        {
            sy = funcCall->substr(CommaIndex + 1, i + 1);

        }

    }

    try
    {

        //std::cout << "sx : " << sx << " sy: "  << sy << std::endl;
        x = std::stoi(sx);
        y = std::stoi(sy);

        product = mul(x, y);

    }

    catch(const std::exception& e)
    {
        //std::cout << "Errors" << std::endl;
        std::cerr << e.what() << '\n';
        product = -1;
    }
    
    return product;

}
int getMulCommandSum(std::string corrLine)
{
    std::string checkLine = corrLine;
    bool found = false;
    bool enabled = true;
    int sum;
    int firstIndex = 0;
    int dontIndex = 0;
    int doIndex = 0;

    while(checkLine.size() > 7)
    {

        
        firstIndex = checkLine.find("mul(" );

        std::cout << "String to check: " << checkLine << std::endl;
        std::cout << "first index: " << firstIndex << std::endl;
        std::string funCall;

        for(int i = 7; i < 12; i++) //checkmax until if both nums were three digit
        {
            std::cout << "i: " << i << std::endl;
            if(checkLine.at(firstIndex + i) == ')')
            {
                funCall = checkLine.substr(firstIndex, i + 1); //this is func call
            
                std::cout << "FUNC CALL:" << funCall << std::endl;
                
                if(convertandCallFunc(&funCall) != -1)
                {
                    sum += convertandCallFunc(&funCall);
                }
                

                checkLine = checkLine.substr(i);

                found = true; 
                break;

                
                
            }

        }

        if(!found)
        {
            if(firstIndex + 4 < checkLine.size())
            {
                checkLine = checkLine.substr(firstIndex + 1); //if not found, ignores current mul ocmmand that is checked
            }
            else
            {
                break; // leaves when theres no more closing parenthese and there are not more mul commands in rest of string
            }
            

        }
        
        
        
        dontIndex = checkLine.find("don't()");
        if (dontIndex != -1)
        {
            doIndex = checkLine.find("do()");
            if (doIndex != -1)
            {
                checkLine = checkLine.substr(0, dontIndex) + checkLine.substr(doIndex + 4); // Adjust to skip "do()"
                enabled = true;
            }
            else
            {
                break;
            }
        }
       
            

    


    }

    return sum;

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
    std::string wholeInput;
    int addingUpEverything = 0;

    while(std::getline(inputFile, line))
    {
        //std::cout << line << std::endl;
        wholeInput += line;;
    }

    std::cout << getMulCommandSum(wholeInput) << std::endl;

    return 0;
}
