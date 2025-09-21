#ifndef BLOCK_H
#define BLOCK_H

#include "Transaction.h"
#include <vector>
#include <string>

class Block {
public:
    int index;
    std::string prevHash;
    std::string hash;
    std::vector<Transaction> transactions;
    long long timestamp;
    int nonce;
    int difficulty;

    Block(int idx, std::vector<Transaction> txs, std::string prev, int diff);

    std::string calculateHash() const;
    void mineBlock();
};

#endif
