#include <iostream>
#include "blockchain.h"
using namespace std;

int main() {
    bool result;
    BlockChain BC_Test;
    Transaction t(10,"Jose","Manuel");
    result = BC_Test.addBlock(t);
    cout <<"Resultado "<<result <<" Size:"<<BC_Test.size()<<endl;
    BC_Test.printhashGenesis();
    return 0;
}

