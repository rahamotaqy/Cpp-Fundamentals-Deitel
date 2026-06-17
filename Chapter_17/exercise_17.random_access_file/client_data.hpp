// client_data.hpp
// Portable ClientData class used by the random-access file exercises.

#ifndef CLIENT_DATA_HPP
#define CLIENT_DATA_HPP

#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

class ClientData {
public:
    ClientData(int accountNumber = 0,
               const std::string& firstName = "",
               const std::string& lastName = "",
               double balance = 0.0);

    void setAccountNumber(int accountNumber);
    int getAccountNumber() const;

    void setFirstName(const std::string& firstName);
    std::string getFirstName() const;

    void setLastName(const std::string& lastName);
    std::string getLastName() const;

    void setBalance(double balance);
    double getBalance() const;

private:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
};

inline ClientData::ClientData(int accountNumber,
                              const std::string& firstName,
                              const std::string& lastName,
                              double balance) {
    setAccountNumber(accountNumber);
    setFirstName(firstName);
    setLastName(lastName);
    setBalance(balance);
}

inline void ClientData::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}

inline int ClientData::getAccountNumber() const {
    return accountNumber;
}

inline void ClientData::setFirstName(const std::string& firstName) {
    std::size_t length = firstName.size();
    length = (length < 10 ? length : 9);
    std::strncpy(this->firstName, firstName.data(), length);
    this->firstName[length] = '\0';
}

inline std::string ClientData::getFirstName() const {
    return firstName;
}

inline void ClientData::setLastName(const std::string& lastName) {
    std::size_t length = lastName.size();
    length = (length < 15 ? length : 14);
    std::strncpy(this->lastName, lastName.data(), length);
    this->lastName[length] = '\0';
}

inline std::string ClientData::getLastName() const {
    return lastName;
}

inline void ClientData::setBalance(double balance) {
    this->balance = balance;
}

inline double ClientData::getBalance() const {
    return balance;
}

inline void outPutLine(std::ostream& output, const ClientData& record) {
    output << std::left << std::setw(10) << record.getAccountNumber()
           << std::setw(16) << record.getLastName()
           << std::setw(11) << record.getFirstName()
           << std::setw(10) << std::fixed << std::setprecision(2)
           << std::right << record.getBalance() << std::endl;
}

#endif // CLIENT_DATA_HPP
