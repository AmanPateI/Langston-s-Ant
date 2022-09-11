/*
Author: Aman Patel
Class: ECE 4122
Last Modified Date: 9/24/2021

Description: Implementaion of langston's ant problem. Takes in the total
             number of moves made and outputs the total number of black squares.

*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>

//Black Square struct
typedef struct Cordinates {
    int x;
    int y;
    std::string color;
} Black_Squares;


int main(int argc, char* argv[]) {

    if (argc < 1) {
        std::cout << "Invalid amount of inputs" << std::endl;
    }
    //unsigned long Number_moves;
    std::cout << "Please enter the total number of moves:" << std::endl;
   // std::cin >> Number_moves;
    const unsigned long Number_moves = std::stof(argv[1]);

    std::unordered_map<std::string, Black_Squares> blackSquares;
    Black_Squares current = {0, 0, "white"};
    int direction = 3; // 0 = north, 1 = east, 2 = south, 3=west
    unsigned long Total_Black_Squares=0;
    for (unsigned long i = 0; i < Number_moves; i++) {
        if (blackSquares.count(std::to_string(current.x) + std::to_string(current.y)) > 0) {
            // check if black or white square
            if (blackSquares.at(std::to_string(current.x) + std::to_string(current.y)).color =="black") {
                Total_Black_Squares--;
                blackSquares.at(std::to_string(current.x) + std::to_string(current.y)).color = "white";
                //current.color = "white";
                switch (direction) {
                    case 0: //north
                    {
                        direction = 3;
                        current.x = current.x - 1;
                        current.y = current.y;
                        break;
                    }
                    case 1: {
                        direction = 0;
                        current.x = current.x;
                        current.y = current.y - 1;
                        break;
                    }
                    case 2: {
                        direction = 1;
                        current.x = current.x + 1;
                        current.y = current.y;
                        break;
                    }
                    case 3: {
                        direction = 2;
                        current.x = current.x;
                        current.y = current.y + 1;
                        break;
                    }
                }
            } else {
                Total_Black_Squares++;
                blackSquares.at(std::to_string(current.x) + std::to_string(current.y)).color = "black";
                current.color = "black";
                switch (direction) {
                    //NORTH
                    case 0: 
                    {
                        direction = 1;
                        current.x = current.x + 1;
                        current.y = current.y;
                        break;
                    }
                    //SOUTH
                    case 1: {
                        direction = 2;
                        current.x = current.x;
                        current.y = current.y + 1;
                        break;
                    }
                    // EAST
                    case 2: {
                        direction = 3;
                        current.x = current.x - 1;
                        current.y = current.y;
                        break;
                    }
                    // WEST
                    case 3: {
                        direction = 0;
                        current.x = current.x;
                        current.y = current.y - 1;
                        break;
                    }
                }
            }
        } else {
            Total_Black_Squares++;
            blackSquares.insert(
                    {std::to_string(current.x) + std::to_string(current.y), current = {current.x, current.y,
                                                                                       "black"}});
            current.color = "black";
            switch (direction) {
                // NORTH
                case 0: 
                {
                    direction = 1;
                    current.x = current.x + 1;
                    current.y = current.y;
                    break;
                }
                // SOUTH
                case 1: {
                    direction = 2;
                    current.x = current.x;
                    current.y = current.y + 1;
                    break;
                }
                // EAST
                case 2: {
                    direction = 3;
                    current.x = current.x - 1;
                    current.y = current.y;
                    break;
                }
                // WEST
                case 3: {
                    direction = 0;
                    current.x = current.x;
                    current.y = current.y - 1;
                    break;
                }
            }
        }
    }
    // Outputting answer to output2.txt
    std::ofstream out("output2.txt");
    out << Total_Black_Squares;
    // Printing result to console
    std::cout<< Total_Black_Squares <<std::endl;
    return 0;
}
