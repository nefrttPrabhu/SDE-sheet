//Eg: Input:[2,1,4,3]  Output:[1,-1,3,-1]

void smallest(vector<int> arr){
    stack<int> s;
    s.push(-1); //-1 coz end wale ke liye arrray mai koi hi he nhi uske baad toh fir -1 by default dal diya arr last mai and also ATQ bhi hi
    int n = arr.size();


    for(int i = n-1 ; i >= 0 ; i--)// peeche se chal rhe 3 -> 4 -> 1 -> 2
    {
        int curr = arr[i]; //I1: 3
        while(!s.empty() && s.top() >= curr) //tabtak pop karte raho jabtak hume current element se chota nhi mil jata ya fir stack empty nhi ho jata
        {
            s.pop(); //I1:inside stack -1 that is < than 3 toh pop nhi hoga
        }
        arr[i] = s.top(); //I1:-1 arr mai last index overwrite karlega ie idhar hua ye ki stack mai hume chota element mil gya and usko humne peeche se arr mai overwrite diye coz array mai kahin se bhi kisiko bhi access kar skte
        s.push(curr); //I1:3 stack mai push ho jayega ie uss current ko stack mai push kar diya check karne ke liye ki next iteration mai usse bada hi kya koi hi agar toh current element at that point else -1
    }
}
