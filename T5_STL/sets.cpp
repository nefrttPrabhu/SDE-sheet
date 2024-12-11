/*
  --> idhar sasb unique koi repeat nhi kar sakta
  --> sab apne aap he sorted mai arrange hote rehta hi 
*/

set<int> st;
    // Insert elements
    st.insert(1);  // {1}
    st.emplace(2); // {1, 2}
    st.insert(4);  // {1, 2, 4}
    st.insert(3);  // {1, 2, 3, 4}
/*
  Functionality of insert in vector can be used also, that only increases efficiency
  begin(), end(),rbegin(),rend(),size(),empty() and swap() are same as those of above
*/

    st={1,2,3,4,5}
    auto it= st.find(3); // it will store 3 returns an iterator that points to the index of three
    auto it= st.find(6); // If 6 is not present in the set st, it2 will store an iterator pointing to st.end() ie it=-1

    st.erase(5); // delete 5 and maintain the sorted order

    auto it= st.find(3);
    st.erase(it);

    int c=st.count(1); // if exist then c=1 else c=0 

    st={1,2,3,4,5}
    auto it1 = st.find(2);  // Find the element 2
    auto it2 = st.find(4);  // Find the element 4
    st.erase(it1, it2);     // Erase all elements from 'it1' to 'it2' (excluding 'it2') st={1,4,5}

    // Find the first element > 3
    auto it_upper = st.upper_bound(3);  // Iterator to 4

    // Find the first element >= 2
    auto it_lower = st.lower_bound(2);  // Iterator to 2












