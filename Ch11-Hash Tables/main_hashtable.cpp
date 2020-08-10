#include <iostream>
#include <string>
#include "hashtable.hpp"
using namespace std;

int main()
{
    HashTable<std::string> htObj(10);
    htObj.direct_address_insert(2, "B");
    htObj.direct_address_insert(3, "C");
    htObj.direct_address_insert(5, "E");
    htObj.direct_address_insert(8, "H");
    htObj.print_table();
    htObj.direct_address_delete(3);
    htObj.print_table();

    ChainedHashTable<std::string> chtObj(10);
    chtObj.chained_hash_insert(1, "A");
    chtObj.chained_hash_insert(1, "AA");
    return 0;
}