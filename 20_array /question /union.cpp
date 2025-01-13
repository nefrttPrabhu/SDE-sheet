/*
int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
Output:
Union of arr1 and arr2 is but we dont repeat any element
1 2 3 4 5 6 7 8 9 10 11 12. 

int arr1[] = {1,2,2,3,4,5};
int arr2[] = {1,2,3,3,5,6};
Output:
{1,2,3,4,5,6}
*/


#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vecto
  while (i < n && j < m) //jab tak i and j both have elements
  {
    if (arr1[i] <= arr2[j]) //arr1 ka element chota hi ya fir equal hi arr2 ke element se eg:1
    {
      if (Union.size() == 0 || Union.back() != arr1[i]) //agar khali hi ya fir abhi tak vo present he nhi hi 
        Union.push_back(arr1[i]); // toh dal do
      i++; // j wahin hi i aage badha hi 
    } 
    else // idhar check ho rha only for arr2 greater hi arr2 ke element se
    {
      if (Union.size() == 0 || Union.back() != arr2[j]) //agar khali hi ya fir abhi tak vo present he nhi hi 
        Union.push_back(arr2[j]); // toh dal do
      j++; // i wahin hi j aage badha hi
    }
  }
  while (i < n) //j exhauseted now only remaining is i elements
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++; // j toh khtm i ko dalo and badhao
  }
  while (j < m) //i exhauseted now only remaining is j elements
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++; // i toh khtm j ko dalo and badhao
  }
  return Union;
}
