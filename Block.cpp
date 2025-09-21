#include "Block.h"
#include "utils.h"
#include <ctime>
#include <iostream>

Block::Block(int idx, std::vector<Transaction> txs, std::string prev, int diff)
    : index(idx), transactions(std::move(txs)), prevHash(std::move(prev)), difficulty(diff), nonce(0) {
    timestamp = time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::string txData;
    for (auto &t : transactions) txData += t.toString();
    std::string data = std::to_string(index) + prevHash + std::to_string(timestamp) + std::to_string(nonce) + txData;
    return sha256(data);
}

void Block::mineBlock() {
    std::string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
    std::cout << "✅ Block mined: " << hash << "\n";
}
