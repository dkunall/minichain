#include "Blockchain.h"
#include <iostream>

Blockchain::Blockchain(int diff, double r) : difficulty(diff), reward(r) {
    chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() {
    std::vector<Transaction> txs;
    return Block(0, txs, "0", difficulty);
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}

void Blockchain::addTransaction(const Transaction &tx) {
    pendingTxs.push_back(tx);
}

void Blockchain::minePendingTransactions(const std::string &minerAddr) {
    Block block(chain.size(), pendingTxs, getLatestBlock().hash, difficulty);
    block.mineBlock();
    chain.push_back(block);

    // Reward miner
    pendingTxs.clear();
    pendingTxs.push_back(Transaction("SYSTEM", minerAddr, reward));
}

double Blockchain::getBalance(const std::string &addr) {
    double balance = 0;
    for (auto &block : chain) {
        for (auto &tx : block.transactions) {
            if (tx.sender == addr) balance -= tx.amount;
            if (tx.receiver == addr) balance += tx.amount;
        }
    }
    return balance;
}

bool Blockchain::isChainValid() {
    for (size_t i = 1; i < chain.size(); i++) {
        if (chain[i].hash != chain[i].calculateHash()) return false;
        if (chain[i].prevHash != chain[i - 1].hash) return false;
    }
    return true;
}

void Blockchain::printChain() {
    for (auto &block : chain) {
        std::cout << "\n--- Block " << block.index << " ---\n";
        std::cout << "Hash: " << block.hash << "\n";
        std::cout << "Prev: " << block.prevHash << "\n";
        for (auto &tx : block.transactions) {
            std::cout << "  - " << tx.toString() << "\n";
        }
    }
}
