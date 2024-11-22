//brute force
set<int>s;
for(auto i:arr)
  s.insert(arr[i]);
int a=0;
for(auto j:s)
  arr[a]=j;



//optimal
int a=0;
for(auto j:arr)
if(arr[a]!=arr[j])
{
arr[a]=arr[j];
a++;
}
