MiniChain – Blockchain Implementation in C++

## Overview
**MiniChain** is a simple blockchain implementation developed in **C++**.  
It demonstrates the **core principles of blockchain technology**—including block generation, cryptographic hashing, proof-of-work mining, transaction management, and ledger validation—using **Object-Oriented Programming (OOP)** and the **Standard Template Library (STL)**.

## Key Features
- **Block Structure** – Each block stores index, timestamp, nonce, transactions, and cryptographic hash.  
- **SHA-256 Hashing** – Ensures immutability and data integrity (via OpenSSL).  
- **Proof-of-Work Consensus** – Mining mechanism with configurable difficulty.  
- **Transaction Handling** – Supports sender → receiver transfers with miner rewards.  
- **Chain Validation** – Detects tampering and verifies consistency across blocks.  
- **Modular Design** – Built with clean separation of classes: `Transaction`, `Block`, and `Blockchain`.


## Project Structure
MiniChain/
│── main.cpp             # Driver code<br>
│── utils.h / utils.cpp  # SHA-256 helper functions<br>
│── Transaction.h/.cpp   # Transaction class<br>
│── Block.h/.cpp         # Block class (mining + hashing)<br>
│── Blockchain.h/.cpp    # Blockchain class (chain management)<br>
│── README.md            # Project documentation<br>
