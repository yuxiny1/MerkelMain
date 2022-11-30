#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>


class CSVReader
{
    public:
     CSVReader();

    // read the file and return a vector of OrderBookEntry
     static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    // write the vector of OrderBookEntry to a file
     static std::vector<std::string> tokenise(std::string csvLine, char separator);
    
    // split a string into tokens
     static OrderBookEntry stringsToOBE(std::string price, 
                                        std::string amount, 
                                        std::string timestamp, 
                                        std::string product, 
                                        OrderBookType OrderBookType);

    private:
    // convert a string to a double
     static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
     
};