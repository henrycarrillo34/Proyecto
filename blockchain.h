#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

//Proy
#include<iostream>
#include<string>
#include <vector>
#include "sha256.h"

using namespace std;

struct Transaction{
//    int id;
    int data;
    string emisor;
    string receptor;
    Transaction(int data,string e,string r):data{data},emisor{e},receptor{r}{};
};

struct Block{
public:
    Block* prevDir;
    string prevHashCode;
    Block* nextDir;
//    string data;
    string hashCode;
    vector<Transaction> operaciones{};

    Block(Block* prevDir, string prevHashCode, Transaction data){
        this->prevDir = prevDir;
        this->prevHashCode = prevHashCode;
//        this->data = data;
        operaciones.push_back(data);
        generateHash();
        this->nextDir = nullptr;
    }

    void addTransaction(){

    }

    void generateHash(){
        string to_hash;
        for(auto const& t:operaciones){
            to_hash += to_string(t.data)+t.emisor+t.receptor;
        }
        hashCode = SHA256::cifrar(to_hash);
    }
};

struct BlockChain{
    Block* Genesis;
    Block* head;
    bool F_first = true;
    int size_{};
public:
    BlockChain(){};
    bool addBlock(Transaction data){
        string hashCode;
        bool valid;
        if (!F_first){
            if(proofOfWork(head)){
                auto it=head;
                head = new Block(head, head->hashCode,data);
                it->nextDir = head;
                valid = true;
            }
            else{
                for(Block* it = head; it != nullptr; it = it->prevDir){
                    //HASH_Function(it->prevHashCode, it->data)
                }
                valid = false;
            }
        }
        else{
            F_first = false;
            Genesis = new Block(nullptr, "000000000000000000000000",data);
            head = Genesis;
            valid = true;
            size_++;
        }
        return valid;
    }

    bool proofOfWork(Block* head){
        bool valid = true;
//        for(Block* it = head; it != nullptr; it = it->prevDir){
//            //it->hashCode = HASH_Function(it->prevHashCode + it->data) // Hashcode
//        }
        for(Block* it = head; it != nullptr; it = it->prevDir){
            if(it->prevHashCode != it->prevDir->hashCode){
                valid = false;
                break;
            }
        }
        return valid;
    }

    int size(){
        return size_;
    }

    void printhashGenesis(){
        cout<<Genesis->hashCode<<endl;
    }
};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
