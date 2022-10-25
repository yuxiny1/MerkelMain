#include "Advisorbot.h"
#include <iostream>
#include <vector>
#include <string>
#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "OrderBook.h"
#include <numeric>
#include <cstdio>

Advisorbot::Advisorbot()
{
};

void Advisorbot::init()
{
    //晚点
    double d;
    std::string input = "";
    try{
        d = std::stod(input);
    }
    catch (const std::exception& e)
    {
    }
    //currentTime = orderBook.getEarliestTime();
    // wallet.insertCurrency("BTC", 10);
    // while(true)
    // {
    //     printCommands();
    //     input = getUserOptionAdvisor();
    //     processUserOptionAdvisor(input);
    // }
    while(true)
    {
        printCommands();
    }
}

void Advisorbot::printCommands()
{

    currentTime = orderBook1.getEarliestTime();
    
    
    //orders = CSVReader::readCSV(filename);


    //std::cout << "get earliest time "<< currentTime <<std::endl;

    while(true){
    // 1 print help
    std::cout << "get earliest time "<< currentTime <<std::endl;

    std::cout << "Help: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "pro: list all available product" << std::endl;
    // 3 make an offer
    std::cout << " min : find miniumn bid or ask for product in current timestep " << std::endl;
    // 4 make a bid 
    std::cout << " max : find maximum bid or ask for product in current timestep " << std::endl;
    // 5 print walle
    std::cout << "avg : find average bid or ask for product in current timestep " << std::endl;
    // 6 continue   
    std::cout << " Continue " << std::endl;

    std::cout << "===== " << std::endl;

    std::string userChoice;

    double userInput= 0;
   
    std::getline(std::cin, userChoice);

    // std::vector<std::string> tokens =CSVReader::tokenise(userChoice,' ');
    // if(tokens.size() !=4)
    // {
    //     std::cout<<"Merkelmain:: " << userChoice<<std::endl;
    // }
    // else 
    // {
    // }
    try{
        userInput = std::stod(userChoice);
        }
    catch (const std::exception&e)
    {
    }

    std::cout<< "you chose :" << userChoice<<std::endl;

    if(userChoice == "help")
    {
        std::cout <<" help will list all important commands. The available commands are help, help<cmd>, avg, time, (etc. list all commands) "<<std::endl;

    }

    if(userChoice == "help avg")
    {
        std::cout<< " compute average ask or bid for the sent product over the sent number of time steps. :: avg ETH/BTC bid 10 -> average ETH/BTC bid over last 10 time steps"<<std::endl;
        std::cout<<"for example : avg ETH/BTC ask"<<std::endl;
        std::cout<<"for example : avg ETH/BTC bid"<<std::endl;
        std::cout<<"for example : avg DOGE/USDT ask"<<std::endl;
        std::cout<<" you can try avg with all products from the list with ask or with bid "<<std::endl;
    }

    if(userChoice == "help prod")
    {
        std::cout<< "pro will list all available products "<<std::endl;
    }

    if(userChoice == "help min")
    {
        std::cout<< " find minimum bid or ask for product in current time step "<<std::endl;
        std::cout<<"for example : min ETH/BTC ask"<<std::endl;
        std::cout<<"for example : min ETH/BTC bid"<<std::endl;
        std::cout<<"for example : min DOGE/USDT ask"<<std::endl;
        std::cout<<" you can try min with all products from the list with ask or with bid "<<std::endl;
    }

    if(userChoice == "help max")
    {
        std::cout<< " find maximum bid or ask for product in current time step "<<std::endl;
        std::cout<<"for example : min ETH/BTC ask"<<std::endl;
        std::cout<<"for example : min ETH/BTC bid"<<std::endl;
        std::cout<<"for example : min DOGE/USDT ask"<<std::endl;
        std::cout<<" you can try max with all products from the list with ask or with bid "<<std::endl;
    }

    if(userChoice == "help predict")
    {
        std::cout<< " find prediction bid or ask for product according to past  10 timesteps (the method for this is moving average) "<<std::endl;
        std::cout<<"for example : predict ETH/BTC ask"<<std::endl;
        std::cout<<"for example : predict ETH/BTC bid"<<std::endl;
        std::cout<<"for example : predict DOGE/USDT ask"<<std::endl;
        std::cout<<" you can try predict with all products from the list with ask or with bid, the predict max or min is accoridng to past 10 timesteps's avearge in the ascending sorted max or min "<<std::endl;
    }
    
     if(userChoice == "prod")
     {
     for (std::string const& p : orderBook1.getKnownProducts())
        {
/** List all available Product: BTC/USDT
 List all available Product: DOGE/BTC
 List all available Product: DOGE/USDT
 List all available Product: ETH/BTC
 List all available Product: ETH/USDT */

          std::cout << "List all available Product: " << p << std::endl;
        }
     }
     

     if(userChoice == "min ETH/BTC ask")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/BTC", currentTime);
        

         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }


     if(userChoice == "max ETH/BTC ask")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/BTC", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }

    
     if(userChoice == "max ETH/BTC bid")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/BTC", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max bid: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }


     if(userChoice == "min ETH/BTC bid")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/BTC", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min bid: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }



//DOGE/BTC
     if(userChoice == "min DOGE/BTC ask")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/BTC", currentTime);
        

         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }


     if(userChoice == "max DOGE/BTC ask")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/BTC", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }

    
     if(userChoice == "max DOGE/BTC bid")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/BTC", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max bid: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }


     if(userChoice == "min DOGE/BTC bid")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/BTC", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min bid: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }



//DOGE/USDT

     if(userChoice == "min DOGE/USDT ask")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/USDT", currentTime);
        

         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }


     if(userChoice == "max DOGE/USDT ask")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }

    
     if(userChoice == "max DOGE/USDT bid")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max bid: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }


     if(userChoice == "min DOGE/USDT bid")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min bid: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }

//ETH/USDT


     if(userChoice == "min ETH/USDT ask")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/USDT", currentTime);
        

         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }


     if(userChoice == "max ETH/USDT ask")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }

    
     if(userChoice == "max ETH/USDT bid")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max bid: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }


     if(userChoice == "min ETH/USDT bid")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min bid: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }

//BTC/USDT

     if(userChoice == "min BTC/USDT ask")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "BTC/USDT", currentTime);
        

         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }


     if(userChoice == "max BTC/USDT ask")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
   {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "BTC/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }

    
     if(userChoice == "max BTC/USDT bid")    
     {
         std::cout << "The max ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "BTC/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " << std::endl;
         std::cout << "Max bid: " << OrderBook::getHighPrice(entries) << std::endl;
         }
     }


     if(userChoice == "min BTC/USDT bid")    
     {
         std::cout << "The min ask for  "<< std::endl;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "BTC/USDT", currentTime);
        
         std::cout << "Asks seen: " << entries.size() <<" Product : " <<entries[0].product << std::endl;
         std::cout << "Min bid: " << OrderBook::getLowPrice(entries) << std::endl;
         }
     }

     if(userChoice == "avg ETH/BTC ask 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "BTC/USDT", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        for(auto x: avgPrice)
        {
            std::cout<<x<<" ";
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp is " << avtPastSum<<std::endl;
    }
    

    //ETH/BTC
         if(userChoice == "avg ETH/BTC bid 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "BTC/USDT", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp is " << avtPastSum<<std::endl;
    }



     if(userChoice == "avg ETH/USDT ask 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/USDT", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp is " << avtPastSum<<std::endl;
    }
    

    //ETH/BTC
         if(userChoice == "avg ETH/USDT bid 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/USDT", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp is " << avtPastSum<<std::endl;
    }

//DOGE/BTC



     if(userChoice == "avg DOGE/BTC ask 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/BTC", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp of ask is " << avtPastSum<<std::endl;
    }
    

    //ETH/BTC
         if(userChoice == "avg DOGE/BTC bid 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/BTC", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp of bid is " << avtPastSum<<std::endl;
    }

//DOGE/USDT


     if(userChoice == "avg DOGE/USDT ask 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/USDT", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp of ask is " << avtPastSum<<std::endl;
    }
    

    //ETH/BTC
         if(userChoice == "avg DOGE/USDT bid 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/USDT", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp of bid is " << avtPastSum<<std::endl;
    }


//BTC/USDT
     if(userChoice == "avg BTC/USDT ask 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "BTC/USDT", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
                avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp of ask is " << avtPastSum<<std::endl;
    }
    

    //ETH/BTC
         if(userChoice == "avg BTC/USDT bid 5")
    {
        std::string past_timestamp1= orderBook1.getPastTIme(currentTime);

        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "BTC/USDT", past_timestamp1);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }

        std::cout << "in the past 5 seconds  we can see: " <<entries[0].product << " " << entries.size() << std::endl;
        //std::vector<int>::iterator it = entries.begin();
        int PastSum;
        PastSum = std::accumulate(avgPrice.begin(), avgPrice.end(),0);
        int avtPastSum;
        avtPastSum = PastSum/entries.size();
        std::cout<< "average of past 5 seconds timestamp of bid is " << avtPastSum<<std::endl;
    }

// Command: avg product ask/bid timesteps
// Purpose: compute average ask or bid for the sent product over the sent number of time steps.
// 2
// Example:
// user> avg ETH/BTC ask 10
// advisorbot> The average ETH/BTC ask price over the last 10 timesteps was 1.0

if(userChoice == "predict max ETH/BTC ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/BTC", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average ETH/BTC ask max price over the last 10 timesteps was "<< predictResult << std::endl;
    
}
    
if(userChoice == "predict min ETH/BTC ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/BTC", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average ETH/BTC ask min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    


if(userChoice == "predict max ETH/BTC bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/BTC", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average ETH/BTC ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min ETH/BTC bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/BTC", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average ETH/BTC ask min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    




//ETH/USDT

if(userChoice == "predict max ETH/USDT ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average ETH/USDT ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min ETH/USDT ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "ETH/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average ETH/USDT ask min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    


if(userChoice == "predict max ETH/USDT bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average ETH/USDT ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min ETH/USDT bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "ETH/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average ETH/USDT ask min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    

//DOGE/USDT

if(userChoice == "predict max DOGE/USDT ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average DOGE/USDT ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min DOGE/USDT ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average DOGE/USDTask min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    


if(userChoice == "predict max DOGE/USDT bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average DOGE/USDT ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min DOGE/USDT bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average DOGE/USDT ask min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    


//DOGE/BTC

if(userChoice == "predict max DOGE/BTC ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/BTC", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average DOGE/BTC ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min DOGE/BTC ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "DOGE/BTC", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average DOGE/BTC Task min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    


if(userChoice == "predict max DOGE/BTC bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/BTC", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average DOGE/BTC ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min DOGE/BTC bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "DOGE/BTC", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average DOGE/BTC ask min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    


//DOGE/BTC

if(userChoice == "predict max BTC/USDT ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "BTC/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average BTC/USDT ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min BTC/USDT ask")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 "BTC/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average BTC/USDT Task min price over the last 10 timesteps was "<< predictResult << std::endl;
}
    


if(userChoice == "predict max BTC/USDT bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "BTC/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average BTC/USDT ask max price over the last 10 timesteps was "<< predictResult << std::endl;
}
    
if(userChoice == "predict min BTC/USDT bid")
{         
//simple moving average is made here .
 std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::bid, 
                                                                 "BTC/USDT", currentTime);
        std::vector<int> avgPrice;
        for(OrderBookEntry e: entries)
        {
            avgPrice.push_back(e.price);
        }
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
        //sort the data and we can get the last max 10 , and avgerge them to predict the next one.
        std::sort(avgPrice.begin(), avgPrice.end(), std::greater<int>());
        // for(auto x: avgPrice)
        // {
        //     std::cout<<x<<" ";
        // }
      int avgPredictSum;
      avgPredictSum = std::accumulate(avgPrice.end()-10, avgPrice.end(),0);

     std::cout<<avgPredictSum<<std::endl;
     int predictResult;
     predictResult = avgPredictSum/10;
     std::cout<< "The average BTC/USDT ask min price over the last 10 timesteps was "<< predictResult << std::endl;
}


//time 

    if(userChoice == "time")
    {
        std::cout << "Current Time is "<< currentTime<<std::endl;
    }


    if(userChoice =="step")
    {
        std::string nowtimestemp = "";

        nowtimestemp = orderBook1.getNextTime(currentTime);
        std::cout << " now at:"  <<  nowtimestemp<<std::endl;
    }

    //std::cout << "Current time is: " << currentTime << std::endl;

    if(userChoice == "popular")
    {

        std::vector<std::string> products;
         for (std::string const& p : orderBook1.getKnownProducts())
        {
        std::vector<OrderBookEntry> entries = orderBook1.getOrders(OrderBookType::ask, 
                                                                 p, currentTime);       
        for (OrderBookEntry e: entries)
        {
            products.push_back(e.product);
        }
        }

        std::sort(products.begin(), products.end());
        std::string last ="";
        last = products.back();
        
        std::cout<< "the most popular product is "<<products[0]<<std::endl;
        std::cout<< "the most unpopular product is "<<last<<std::endl;
    }


}
}

//void Advisorbot:: 
void Advisorbot::avg()
{

};
void Advisorbot::predict()
{

};
void Advisorbot::time()
{

};
void Advisorbot::step()
{

};

// void Advisorbot::init()
// {
//     int input;
//     while(true)
//     {
//         printCommands();
//         input = getUserChoice();
//         processUserChoice();
//     }
// }

// int Advisorbot::getUserChoice()
// {
//     int userChoice =0 ;
//     std::string line;
//     std::cout << "Make your choice help or commands"<< std::endl;
//     std::getline(std::cin, line);
//     try{
//         userChoice= std::stoi(line);
//     }catch(const std::exception&e)
//     {

//     }
//     std::cout<< "Your are asking for "<< userChoice <<std::endl;
//     return userChoice;

// };

// void Advisorbot::processUserChoice(int)
// {
//     if(userChoice ==0)
//     {
//         std::cout<< "Wrong command. return to help to command again"<<std::endl;
//    }

// };
