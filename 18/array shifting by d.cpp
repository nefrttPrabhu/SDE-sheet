// brute force method
temp[]=[1,2,3]
for(i=d;i<n;i++)
  arr[i]=arr[n-d];  // bache hue arr mai overwrite kar diye starting mai as other are stored in temp 
for(i=n-d;i<n;i++)
  arr[i]=temp[i-(n-d)]; // fir temp wale add kardiye 

//optimal
reverse(a,d)   //[3,2,1,4,5,6,7]
reverse(a+d,n) //[3,2,1,7,6,5,4]
reverse(a,n)   //[7,6,5,4,1,2,3]
