//
//  main.cpp
//  Кошелек
//
//  Created by Станислав Егоров on 24.01.2024.
//

#include <iostream>
#include <sstream>

struct SCreditCard {
    int mNumber;
    std::string mExpirationDate;
    double mSumm;
    double mCredit;
    int mCvv;

    int Number() { return mNumber; }
    void Number(int value) { mNumber = value; }

    std::string ExpirationDate() { return mExpirationDate; }
    void ExpirationDate(std::string value) { mExpirationDate = value; }


    double Credit() { return mCredit; }
    void Credit(double value) { mCredit = value; }

    double Summ() { return mSumm; }
    void Summ(double value) { mSumm = value+Credit(); }

    int CVV() { return mCvv; }
    void CVV(int value) { mCvv = value; }

    void SummChangedBy(double amount) { mSumm += amount; }
    void CreditChangedBy(double amount) { mCredit += amount; }

    std::string NumberString() {
        std::ostringstream ss;
        ss << mNumber;
        return ss.str();
    }

    std::string CreditString() {
        std::ostringstream ss;
        ss << mCredit;
        return ss.str();
    }

    std::string SummString() {
        std::ostringstream ss;
        ss << mSumm;
        return ss.str();
    }

    std::string CVVString() {
        std::ostringstream ss;
        ss << mCvv;
        return ss.str();
    }

    void TransferTo(double amount, SCreditCard& to) {
        if (Credit() < amount)std::cout << "Not enough for transfer. ";
        CreditChangedBy(-amount);
        SummChangedBy(-amount);
        to.SummChangedBy(amount);
    }
    void TransferFrom(double amount, SCreditCard& from) {
        if (from.Credit() < amount)std::cout << "Not enough for transfer. ";
        SummChangedBy(amount);
        from.CreditChangedBy(-amount);
        from.SummChangedBy(-amount);
    }

    std::string GetString() {return  "Credit card number: " + NumberString() + "| Expiration Date: "
        + ExpirationDate() + "| Summ: " + SummString() + "| Credit: " + CreditString() + "| CVV: " + CVVString(); }
    void Print() {std::cout << GetString()<<"\n"; }
};

SCreditCard* CreateCreditCardint (int num,std::string expirDate,double sum,double credit,int cvv) {
    SCreditCard* result = new SCreditCard;
    result -> Number(num);
    result->ExpirationDate(expirDate);
    result ->Credit(credit);
    result ->Summ(sum);
    result ->CVV(cvv);
    return result;
}

struct SDebitCard
{
    int mNumber;
    std::string mExpirationDate;
    double mSumm;
    int mCvv;

    int Number() { return mNumber; }
    void Number(int value) { mNumber = value; }

    std::string ExpirationDate() { return mExpirationDate; }
    void ExpirationDate(std::string value) { mExpirationDate = value; }

    double Summ() { return mSumm; }
    void Summ(double value) { mSumm = value; }

    int CVV() { return mCvv; }
    void CVV(int value) { mCvv = value; }

    void SummChangedBy(double amount) { mSumm += amount; }

    std::string NumberString() {
        std::ostringstream ss;
        ss << mNumber;
        return ss.str();
    }

    std::string SummString() {
        std::ostringstream ss;
        ss << mSumm;
        return ss.str();
    }

    std::string CVVString() {
        std::ostringstream ss;
        ss << mCvv;
        return ss.str();
    }

    void TransferTo(double amount, SDebitCard&to){
        if (Summ() < amount)std::cout << "Not enough for transfer. ";
        SummChangedBy(-amount);
        to.SummChangedBy(amount);
    }
    void TransferFrom(double amount, SDebitCard& from){
        if (from.Summ() < amount)std::cout << "Not enough for transfer. ";
        SummChangedBy(amount);
        from.SummChangedBy(-amount);
    }
    std::string GetString() {
        return  "Debit card number: " + NumberString() + "| Expiration Date: "
            + ExpirationDate() + "| Summ: " + SummString() + "| CVV: " + CVVString();
    }
    void Print() { std::cout << GetString(); }
};

struct SWallet
{
    std::string sWalletName;
    unsigned int sSumOfMoney;

    std::string Name() { return sWalletName; }
    void Name(std::string value) { sWalletName = value; }

    int Money() { return sSumOfMoney; }
    void Money(int value) { sSumOfMoney = value; }

    void MoneyChangedBy(double amount) { sSumOfMoney += amount; }

    std::string MoneyString() {
        std::ostringstream ss;
        ss << sSumOfMoney;
        return ss.str();}

    void TransferTo(double amount ,SWallet& wallet) {
        if (Money() < amount)std::cout << "Not enough money for transfer. ";
        MoneyChangedBy(-amount);
        wallet.MoneyChangedBy(amount);
    }

    void TransferFrom(double amount, SWallet& wallet) {
        if (wallet.Money() < amount)std::cout << "Not enough money for transfer. ";
        MoneyChangedBy(amount);
        wallet.MoneyChangedBy(-amount);
    }
};

int main()
{
    SCreditCard * card1 = CreateCreditCardint(1023131,"augost/2222",11037,1100000,123);
    card1->Print();
}
