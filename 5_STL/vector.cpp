/*
   --> help to cope for dynamic array i.e size can be increaded when needed 
   -->vector are stored in single linked list due to which the insertion cost more for it than a list which in tern uses doubly linked list
*/


1. vector<int> v;

2. vector<int> v(5);
   vector<int> v(5,10);
   v.push_back(1);
   v.emplace_back(1);

3. vector<pair<int,int>> v;
   v.push_back({1,2});  //isko jaise v input leta waisa he input frame karke dena hota nhi toh error deta
   v.emplace_back(1,2); //ye apne aap he jaan leta hi ki v konse type ka input le rha hi toh automatic convert kardeta hi 

4. printing in vector
   cout<<v[i];
   cout<<v.at(i);

5. pointer operation in vector
 /*
    rend()=-1             end()=5;
      |                     |
     -1  0   1   2   3   4  5
   v =_{ 1 , 2 , 3 , 4 , 5 }_; 
         |               | 
       begin()=1      rbegin()=4

*/      
   v.begin();  // points at the 1st memory address of the vector
   v.end();    // points at the last+1 memory address of the vector 
   v.rbegin(); // points at the last memory address of the vector
   v.rend();   // points at the before 1st address of the vector

6. iterator in vector
   vector<int>::iterator it = v.begin(); //

7. iterating through the vector 
   a) int size = sizeof(arr) / sizeof(arr[0]); 
      for (int i = 0; i < size; i++) {
          cout << arr[i] << " ";  
   
   b) for (int i = 0; i < v.size(); i++) 
        cout << arr[i] << " ";

   c) for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        cout << *(it) << " ";

   d) for(auto i : v)
        cout << i << " ";

   e) for(auto it=v.begin();it!=v.end();it++)
        cout << *(it) << " ";

8. v={1,2,3,4,5}  ,   vv={6,7,8,9}
   v.erase(v.begin()+2); //can remove any element v={1,2,4,5}
   v.erase(v.begin()+1,v.begin()+3); // v(start,end-1) v={1,4,5}

   v.insert(v.begin(),300); // v={300,1,2,3,4,5}
   v.insert(v.begin()+2,2,300) // v={1,2,3,300,300,4,5}
   v.insert(v.begin()+3,vv.begin()+1,vv.end()); // v={1,2,3,4,7,8,9,5}

   v.pop_back(); // last element pops v={1,2,3,4}

   v.swap(vv); // v={6,7,8,9}

   v.clear(); // v={}

9. sorting
   v.sort(v.begin(),v.end());               // sort entire vector
   v.sort(v.begin(),v.end(),greater<int>);  // sort in reverse order
   v.sort(v.begin()+2,v.begin()+4);         // sort the range from index 2 to 3




















