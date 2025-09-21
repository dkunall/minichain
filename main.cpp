#include "Blockchain.h"
#include <iostream>
using namespace std;

int main() {
    Blockchain myChain(2, 100);

    myChain.addTransaction(Transaction("jeetu", "ram", 10));
    myChain.addTransaction(Transaction("ram", "kunal", 5));

    cout << "\n Mining pending transactions...\n";
    myChain.minePendingTransactions("Miner1");
    cout << "Miner1 balance: " << myChain.getBalance("Miner1") << "\n";

    myChain.addTransaction(Transaction("jeetu", "kunal", 20));

    cout << "\n Mining again...\n";
    myChain.minePendingTransactions("Miner2");
    cout << "Miner2 balance: " << myChain.getBalance("Miner2") << "\n";

    cout << "\nBlockchain valid? " << (myChain.isChainValid() ? "Yes" : "No") << "\n";

    myChain.printChain();
    return 0;
}
