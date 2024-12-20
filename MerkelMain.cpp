#include "MerkelMain.hpp"
#include <iostream>
#include <vector>
#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"
MerkelMain::MerkelMain()
{
}
void MerkelMain::init()
{
    loadOrderBook();
    int input;
    while (input)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}
void MerkelMain::loadOrderBook()
{
    orders = CSVReader::readCSV("20200317.csv");
}
void MerkelMain::printMenu()
{
    std::cout << "======================" << std::endl;
    std::cout << "      MerkleRex Menu      " << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << "1. Print help" << std::endl;
    std::cout << "2. Print exchange stats" << std::endl;
    std::cout << "3. Place an ask" << std::endl;
    std::cout << "4. Place a bid" << std::endl;
    std::cout << "5. Print wallet" << std::endl;
    std::cout << "6. Continue" << std::endl;
    std::cout << "======================" << std::endl;
    // std::cout << "Please select a choice (1-6): ";
}
void MerkelMain::printHelp()
{
    std::cout << "Help: Here are the options you can choose from." << std::endl;
}
void MerkelMain::printMarketStats()
{
    std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
    unsigned int bids = 0;
    unsigned int asks = 0;
    for (const OrderBookEntry &e : orders)
    {
        if (e.orderType == OrderBookType::ask)
        {
            asks++;
        }
        if (e.orderType == OrderBookType::bid)
        {
            bids++;
        }
    }
    std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;
}
void MerkelMain::enterOffer()
{
    std::cout << "Placing an ask: Enter the amount you wish to (sell)." << std::endl;
}
void MerkelMain::enterBid()
{
    std::cout << "Placing a bid: Enter the amount you wish to bid(buy)." << std::endl;
}
void MerkelMain::printWallet()
{
    std::cout << "Wallet: Your current wallet is empty." << std::endl;
}
void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Continuing with the application..." << std::endl;
    std::cout << "Goint to next time frame" << std::endl;
}
int MerkelMain::getUserOption()
{
    int userOption;

    std::cout << "Please select a choice (1-6): ";
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    if (userOption <= 0 || userOption > 6)
    {
        std::cout << "Invalid choice. Please select a number between 1 and 6." << std::endl;
        std::cout << "----------------------" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterOffer();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotoNextTimeframe();
    }
}