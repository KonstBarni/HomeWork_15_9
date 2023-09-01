#pragma once
#include <iostream>
#include <string.h>

#define NAMELENGTH 40  // максимальная длина имени

typedef std::string LoginName; // тип Логин

class HashTable { // хэш таблица
    public:
    
        HashTable();
        ~HashTable();
        void add(LoginName login, std::string pass);
        void del(LoginName login);
        std::string find(LoginName login);
        std::string hash_pass(std::string pass);
    private:
    
        enum enPairStatus {
            free,
            engaged,
            deleted
        };
    
        struct Pair { // пара ключ-значение
            
            Pair(): 
                login(""), 
                password(""),
                status(enPairStatus::free)
            {}
            Pair(LoginName log, std::string pass):
                login(log), 
                password(pass),
                status(enPairStatus::engaged) {};

            Pair& operator = (const Pair& other) {
                password =  other.password;
                login = other.login;
                status = other.status;
                return *this;
            }
            
            bool operator == (const Pair& other) {
                return  status == other.status &&
                        (status != enPairStatus::engaged || 
                        (password == other.password && (login == other.login)));
            }
            
            LoginName login;
            std::string password;
            
            enPairStatus status;
        };
        void resize();
        int hash_func(LoginName login, int offset);
        Pair* array;
        int mem_size;
        int count;
};