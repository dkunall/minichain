#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include "Transaction.h"
#include <vector>
#include <string>

class Blockchain {
private:
    std::vector<Block> chain;
    int difficulty;
    std::vector<Transaction> pendingTxs;
    double reward;

public:
    Blockchain(int diff = 2, double r = 50.0);

    Block createGenesisBlock();
    Block getLatestBlock() const;

    void addTransaction(const Transaction &tx);
    void minePendingTransactions(const std::string &minerAddr);
    double getBalance(const std::string &addr);
    bool isChainValid();
    void printChain();
};

#endif
