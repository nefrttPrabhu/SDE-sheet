//self ending passed variable ki value alter karke jitne bhi waiting honge usko complete karke self end ho jayega and no return of the value as this is void fng
void fun(int n, int sum){
  if(n == 0)
    return;
  sum = sum + n;
  fun(n-1,sum);
}

//it will return the value to its caller as its return type is int
int fum(int n){
  if(n == 0)
    return 0;
  return n + sum(n-1); //I1: 5 + sum(5-1) -> I2: 4 + sum(4-1) -> I3: 3 + sum(3-1) -> I4: 2 + sum(2-1) -> I5: 1 + sum(1-1)=0 return 0;
                       //main=15 <- I1: 5 + 10 <- I2: 4 + 6 <- I3: 3 + 3 <- I4: 2 + 1 <- I5: 1 + 0 <-
}

