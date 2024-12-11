/* jaise ki humlog ek point ke coordinates store karte waise he (x,y)
   ye bhi dynamic hota hi jab need tab dalo ans size inc
*/
1. pair<int,int> p;

2. pair<int,int> p = {1,2};

3. pair<int, pair<int,int>> p = {1,{3,4}};

cout<<p.first;             // {1}
cout<<p.second;            // {3,4}
cout<<p.second.first;      // {3}
cout<<p.second.second;     // {4}


   
