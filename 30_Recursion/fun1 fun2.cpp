// all due 1st increse then pass
fun1(int n){
if(n == 0)
  return ;
  
  cout<<( n );
  fun2(n-2);
  cout<<( n);
}

fun2(int n){
if(n == 0)
  return ; 
  
  cout<<( n );
  fun1(++n);
  cout<<( n );
}
/*
f2 n=0 | return |
f1 n=2 |   n=2  | -> 4
f2 n=1 | n=1->2 | -> 8 due to ++n
f1 n=3 |   n=3  | -> 4
f2 n=2 | n=2->3 | -> 8 due to ++n
f1 n=4 |   n=4  | -> 4
f2 n=3 | n=3->4 | -> 8 due to ++n
f1 n=5 |   n=5  | -> 4

                        1              f1(5)
                                     /   |   \
                        2    print(5)  f2(3)   print(5)   16
                                     /   |   \
                        3    print(3)  f1(4)   print(4)   15
                                     /   |   \
                        4    print(4)  f2(2)   print(4)   14
                                     /   |   \
                        5    print(2)  f1(3)   print(3)   13
                                     /   |   \
                        6    print(3)  f2(1)   print(3)   12
                                     /   |   \
                        7    print(1)  f1(2)   print(2)   11
                                         |
                        8    print(2)  f2(0)   print(2)   10
                                         |
                        9             return

output: 5 3 4 2 3 1 2 2 2 3 3 4 4 5
  */

//all due to 1st pass then increase
fun1(int n){
if(n == 0)
  return ;
  
  cout<<( n );
  fun2(n-2);
  cout<<( n);
}

fun2(int n){
if(n == 0)
  return ; 
  
  cout<<( n );
  fun1(n++);
  cout<<( n );
}
/*
f2 n=0 | return |
f1 n=2 |   n=2  | -> 4
f2 n=1 |   n=1  | -> 8 due to n++
f1 n=3 |   n=3  | -> 4
f2 n=2 |   n=2  | -> 8 due to n++
f1 n=4 |   n=4  | -> 4
f2 n=3 |   n=3  | -> 8 due to n++
f1 n=5 |   n=5  | -> 4

                        1              f1(5)
                                     /   |   \
                        2    print(5)  f2(3)   print(5)   16
                                     /   |   \
                        3    print(3)  f1(4)   print(3)   15
                                     /   |   \
                        4    print(4)  f2(2)   print(4)   14
                                     /   |   \
                        5    print(2)  f1(3)   print(2)   13
                                     /   |   \
                        6    print(3)  f2(1)   print(3)   12
                                     /   |   \
                        7    print(1)  f1(2)   print(1)   11
                                         |
                        8    print(2)  f2(0)   print(2)   10
                                         |
                        9             return

output: 5 3 4 2 3 1 2 2 1 3 2 4 3 5
  */

//A1: output: 5 3 4 2 3 1 2 2 2 3 3 4 4 5
//A2: output: 5 3 4 2 3 1 2 2 1 3 2 4 3 5
