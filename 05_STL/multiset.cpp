/*
  --> allows repeatation
  --> all are sorted
*/


    std::multiset<int> ms;

    ms.insert(1);  // Inserts 1 into the multiset
    ms.insert(1);  // Inserts another 1 (multiset allows duplicates)
    ms.insert(1);  // Inserts another 1

    ms.erase(1);  // Erases all occurrences of 1 from the multiset

    int cnt = ms.count(1);  // Returns the number of occurrences of 1 in the multiset

    ms.insert(1);  // Inserts another 1
    ms.insert(1);  // Inserts another 1

    ms.erase(ms.find(1));  // Erase one occurrence of 1 (finds the first occurrence) instead of erasing the elements erase the iterator address form the memory eventually loosing acess to the address it having value as 1
    
    ms.erase(ms.find(1), ms.find(1) + 2);  // Erase the range of elements from the first occurrence of 1

