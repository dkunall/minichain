#include "Transaction.h"

Transaction::Transaction(std::string s, std::string r, double a)
    : sender(std::move(s)), receiver(std::move(r)), amount(a) {}

std::string Transaction::toString() const {
    return sender + " -> " + receiver + " : " + std::to_string(amount);
}
