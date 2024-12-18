#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

bool checkReportSafe(std::vector<int>* levels)
{
    bool increasing = true;
    bool decreasing = true;

    //checking for all increasing

    int beforeNum = levels->at(0);

    for(int i = 1; i < levels->size(); i++)
    {
        if(levels->at(i) < beforeNum)
        {
            increasing = false;
            // std::cout << "found decreasing num" << std::endl;
            // std::cout << "CUrrent Num: " << levels->at(i) << " Beofrenum: " <<  beforeNum << std::endl;
            break;
        }

        beforeNum = levels->at(i);
    }

    //checking for all decreasing
    beforeNum = levels->at(0);
    for(int i = 1; i < levels->size(); i++)
    {
        if(levels->at(i) > beforeNum)
        {
            decreasing = false;
            //std::cout << "found increasing num" << std::endl;
            break;
        }
        beforeNum = levels->at(i);
    }

    //adjacent elvels differ by at least one and at most 3
    beforeNum = levels->at(0);
    bool secondCondition = false;

    for(int i = 1; i < levels->size(); i++)
    {
        //std::cout << "Checking difference condition" << std::endl;
        if((std::abs(beforeNum - levels->at(i)) < 1) || (std::abs(beforeNum - levels->at(i)) > 3))
        {
            //std::cout << "Differnce between " << beforeNum << " and " << levels->at(i) << " is " << (std::abs(beforeNum - levels->at(i))) << std::endl;
            //std::cout << "found num where level diff great than 3 or less than 1" << std::endl;
            return false;
        }

        beforeNum = levels->at(i);
    }

    secondCondition = true;

    if((increasing || decreasing) && secondCondition)
    {
        return true;
    }

}
int main()
{
    std::ifstream inputFile("nuclearPlantData.txt");

    if(!inputFile)
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    std::string levelString;
    std::string line;
    std::vector<int> numbers;
    int numOfReportsSafe = 0;



    while (std::getline(inputFile, line))
    {
        std::cout << "Line: " << line << std::endl;
        std::stringstream ss(line);
        int num;

        while(ss >> num)
        {
            numbers.push_back(num);
        }

        if(checkReportSafe(&numbers))
        {
            numOfReportsSafe++;
        }

        numbers.clear();

    }

    
    std::cout << numOfReportsSafe << std::endl;

   



    inputFile.close();
    return 0;
}
    


