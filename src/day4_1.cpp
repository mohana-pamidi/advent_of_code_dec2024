#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
//#define DEBUG

/*
    Params: Point to vector of Strings, metaphorically a 2D grid; (row, col) coordinate
    Return: True if "xmas" was found in any of 8 directions at specified row, col coordinte and false if not 
*/

int checkNeighbors(std::vector<std::string>* grid, int row, int col)
{
    //dirrections in (x,y)
    //starts at bottom left diagonally, sweeps circle aroudn pt
    std::vector<int> x = {-1, -1, -1, 0, 1, 1,  1,  0};
    std::vector<int> y = {-1,  0,  1, 1, 1, 0, -1, -1};
    std::string word = "XMAS";
    int numFound = 0;

    //std::cout << "Checking: " << row << " , " << col << " ------------------" << std::endl;
    //int currX = col, currY = row;


    if (grid->at(row).at(col) != word.at(0))
    {
        #ifdef DEBUG
            std::cout << grid->at(row).at(col) << " != " << word.at(0) << std::endl;
        #endif

        return false;
    }

    int width = grid->at(0).size();
    int height = grid->size();

    for(int i = 0; i < 8; i++)
    {
        int k;
        //std::cout << "*************************i: " << i << std::endl;
        // int width = grid->at(0).size();
        // int height = grid->size();

        int currX = col + x[i], currY = row + y[i];

        for(k = 0; k < word.size() - 1; k++) //goes to minus 1 because we alredy check current letter e are on, so only checking three more letters
        {

            if(currX >= width || currX < 0 || currY >= height || currY < 0)
            {
                break;
            }

            #ifdef DEBUG
                std::cout << "Letters Checking: " << grid->at(currY).at(currX) << " at ( " << currX << " , " << currY << " )" << std::endl;
            #endif

            if(word.at(k + 1) != grid->at(currY).at(currX)) // k+1 because we are chekcign the next three letters in xmas. 
            {
                std::cout << word.at(k + 1) << " != " << grid->at(currY).at(currX) << std::endl;
                break;
            }
            //std::cout << "Currx: " << currX << " currY: " << currY << std::endl;
            currX += x[i], currY += y[i];

            //currLetter = grid->at(currY).at(currX);


        } 

        if(k == word.size() - 1) //iterator k ends at three since chekcing if three letters are same;
        {
            numFound++;
        }
        
    }

    return numFound;
    
}
int main()
{
    std::ifstream inputFile("wordSearch.txt");
    std::vector<std::string> puzzle;
    int sum = 0;
    
    
    if(!inputFile)
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    
    std::string line;

    while(std::getline(inputFile, line))
    {
        puzzle.push_back(line);
    }

    for(int row = 0; row < puzzle.size(); row++)
    {
        for(int col = 0; col < puzzle.at(row).size(); col++)
        {
            std::cout << checkNeighbors(&puzzle, row, col) << "---------------------------" << std::endl;
            sum += checkNeighbors(&puzzle, row, col);
        }
        
    }

    std::cout << sum << std::endl;
    

    // #ifdef DEBUG
    
    //     for(int i = 0; i < puzzle.size(); i++)
    //     {
    //         std::cout << puzzle[i] << std::endl; 
    //     }
    
    // #endif
    
    
    return 0;
}
