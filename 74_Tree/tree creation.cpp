// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node // struct type a data coz koi bhi type a data types ko store kar sakta hi 
{
    int data; // int type stored hi 
    struct node* left; //pointer type stored hi
    struct node* right; //pointer type stored hi
    node(int val){
        data=val; //root node hi 
        left=NULL;right=NULL; //starting mai kya khali he honge right and left
    }
};

int main() {
    struct node* root=new node(1); //
    root ->left=new node(2); //apne se new node create kiya hi 
    root ->right=new node(3); // apne se right node create kiya hi
    root ->left ->right=new node(5); // apne se left ke right node ko value assign kari hi waise he karte jao as per our need
    return 0;
}
