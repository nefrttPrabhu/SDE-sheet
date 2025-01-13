//Eg: n=16
// iska answer hamesha false he ayega coz waiting wale return without seeing any condition returning false reason stated below
bool isPrime(int n){
  if(n == 1) //for I1: 16!=1 I2:8!=1 I3:4!=1 I4:2!=1 I5:1==1 not it will return true
    return true;
  isPrime(n/2) //idhar hoga ye ki I1: 16/2=8 pass hua waiting mai L7 I2: 8/2=4 pass hua waiting mai L7 I3: 4/2=2 pass hua waiting mai L7 I4: 2/2=1 pass hua waiting mai L7
    return false; // ab jaise he n=1==1 in I4 hua return hua true and L7 waiting se execution mai jayegi then return hoga false for I3 then return false for I2, false for I1, false for I1, I return false main 
}

// iska alwawys return true he hoga coz false unreachable hi reason stated below
bool isPrime(int n){
  if(n == 1) // for I1: 16!=1 I2:8!=1 I3:4!=1 I4:2!=1 I5:1==1 not it will return true 
    return true;
  return isPrime(n/2); //idhar hoga ye ki I1: 16/2=8 pass hua waiting mai L14 I2: 8/2=4 pass hua waiting mai L14 I3: 4/2=2 pass hua waiting mai L14 I4: 2/2=1 pass hua waiting mai L14 
  return false; //aise ye false kabhi aa he nhi payega coz I4 se return hua true and I3 I2 ko and I2 I1 ko and I1 main ko true return karke chalta banega wahi false waiting mai he reh jayega
}
