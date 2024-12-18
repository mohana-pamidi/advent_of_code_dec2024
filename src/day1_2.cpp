#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> leftSide;
std::vector<int> rightSide;


int checkFrequency(int checkNum)
{
    int count = 0;

    for(int i = 0; i < rightSide.size(); i++)
    {
        if(rightSide.at(i) == checkNum)
        {
            count++;
        }
    }

    return count;
}
int main()
{
    std::ifstream inputFile("distances.txt");

    if(!inputFile)
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    int num1, num2;

    while(inputFile >> num1 >> num2)
    {
        leftSide.push_back(num1);
        rightSide.push_back(num2);
    }

    int sum;

    for(int i = 0; i < leftSide.size(); i++)
    {
        int numToCheck = leftSide.at(i);
        sum += numToCheck * checkFrequency(numToCheck);
            
    } 

    std::cout << sum << std::endl;

    inputFile.close();

    return 0;
}

