#pragma once

#include <string>
#include <map>
#include <iostream>
#include "OrderBook.h"
#include "CSVReader.h"



class Advisorbot
{

    public:
        Advisorbot();
        /** call this to start the interaction */
        void init();
        void printCommands();

    private:
        /** list all availbhle commands */
        /** example user>help. and advisorbot> the available commands are help, help <cmd>, avg, time, (etc, list all commands 
         */


        void HelpCmd();
        /** user>help avg,  avg ETH/BTC bid 10-> average ETH/BTC bid over last 10 time steps */
        void prod();
        /** list available products examplje: user>prod, advisorbot>ETH>
         */
         
        void min();
        /**  command: mi nproduct bid/ask, purpose: find minumn bid or ask for product in current time step . Example: user>min ETH>BTC ask ; advisorbot> the min ask for ETH/BTC is 1.0        */
        void max();
        /** command : max prodcut bid/ask; purpose: find maximum bid or ask for prodcut in current time step ; example:
         * User> max ETH/BTC as 
         * advisor>the max ask for ETH/BTC is 1.0 */
         void avg();
         void predict();
         void time();
         void step();
         void popular();
         int getUserChoice();
         void processUserChoice();
    
    	OrderBook orderBook1{"20200601.csv"};
        
        std::string currentTime;

      //  std::vector<OrderBookEntry> orders;

};