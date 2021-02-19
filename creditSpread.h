//
// Created by Arnav Hiray on 1/21/21.
//

#ifndef COMPFIN_CREDITSPREAD_H
#define COMPFIN_CREDITSPREAD_H

#include <iostream>
#include <vector>


using namespace std;
class creditSpread{
private:
    int collateral = 0;
    int credit= 0;
    int initialAmount = 0;
    int currentAmount = 0;
    int freqWeek = 0;
    int weeks = 0;
    int secure = 0;
    int secureFreq = 0;
    bool secureFunds = false;
public:
    creditSpread(int coll, int cred, int initAmount, int freq, int w){
        collateral = coll;
        credit = cred;
        initialAmount = initAmount;
        currentAmount = initAmount;
        freqWeek = freq;
        weeks = w;
    }
    void setSecure(int freq){
        secureFreq = freq;
    }
    void setSecureFund(bool sec){
        secureFunds = sec;
    }
    void setWeek(int w){
        weeks = w;
    }
    void setCredit(int cr){
        credit = cr;
    }
    int returnSecure(){
        return secure;
    }
    int returnCurrAmount(){
        return currentAmount;
    }
    int returnInitAmount(){
        return initialAmount;
    }
    int returnSecureFreq(){
        return secureFreq;
    }
    int calcSpread(){
        return int(floor(currentAmount/collateral) * credit);
    }
    bool returnIfSecure(){
        return secureFunds;
    }
    void simSpread(){
        for( int i = 0; i < freqWeek * weeks + freqWeek; i++){
            if(secureFunds) {
                switch (int(floor(i/2)) % secureFreq) {
                    case 0:
                        secure += calcSpread();
                        currentAmount -= calcSpread();
                        break;
                    default:
                        currentAmount += calcSpread();
                        break;

                }
            }else {
                currentAmount += calcSpread();
            }

        }
    }
    double weeklyCAGR(){
        return pow(currentAmount/initialAmount, 1/(double)weeks) - 1 ;
    }
    void print(){
        cout << "The initial amount was: " << initialAmount << endl;
        cout << "The ending amount is: " << currentAmount  << endl;
        cout << "The weekly CAGR: " << weeklyCAGR() << " or " << weeklyCAGR() * 100 << "%" << endl;
        if (secureFunds){
            cout << "The amount of secured funds: " << secure << " every " << returnSecureFreq() << " weeks"<< endl;
        }
    }

};
void printCSVector(creditSpread cs){
    cout << "The initial amount was: " << cs.returnInitAmount() << endl;
    cout << "The ending amount is: " << cs.returnCurrAmount()  << endl;
    cout << "The weekly CAGR: " << cs.weeklyCAGR() << " or " << cs.weeklyCAGR() * 100 << "%" << endl;
    if (cs.returnIfSecure()){
        cout << "The amount of secured funds: " << cs.returnSecure() << " every " << cs.returnSecureFreq() << " weeks"<< endl;
    }
}

creditSpread maxSecure(vector<creditSpread> cs){
    pair<int, int> maxSec;
    int index = 0;
    for( int i = 0; i < cs.size(); i++){
        int sec = cs.at(i).returnSecure();
        if (sec > maxSec.second){
            maxSec.second = sec;
            maxSec.first = i;
            index = i;
        }
    }
    return cs.at(index);
}


#endif //COMPFIN_CREDITSPREAD_H
