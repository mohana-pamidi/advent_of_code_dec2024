#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool comparetor(int i, int j)
{
    return i < j;
}
int main()
{
    std::ifstream inputFile("includes/distances.txt");

    if(!inputFile)
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<int> leftSide;
    std::vector<int> rightSide;

    int num1, num2;

    while(inputFile >> num1 >> num2)
    {
        leftSide.push_back(num1);
        rightSide.push_back(num2);
    }

    std::sort(leftSide.begin(), leftSide.end(), comparetor);
    std::sort(rightSide.begin(), rightSide.end(), comparetor);
    int sum = 0;
    for(int i = 0; i < leftSide.size(); i++)
    {

        sum += std::abs(leftSide.at(i) - rightSide.at(i));
    }

    std::cout << sum << std::endl; 
    inputFile.close();

    return 0;
}

