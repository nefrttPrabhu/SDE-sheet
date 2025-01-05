/* Condition: sare naukar malik ek dusare pe andha true karte hi 
1) main ne bheja 16 ko, 1 nhi hi neeche gya  8 bana, 16 aaram kar rha bola 8 se iska answer batao, 8 bola ji malik usne dekha mera koi naukar hi?
2) 8 check hua 1 hi kya? nhi,8 16 se bola ji malik usne dekha mera koi naukar hi? 4 bana, 8 aaram kar rha, vo apne naukar 4 ka wait kar rha ye dekhega answer kya hi problem ka
3) 4 bheja, 1 nhi hi neeche gya 2 bana, 4 aaram karne laga, 2 ka wait karn rha 
4) 2 bheja, 1 nhi hi neeche gya 1 bana, 2 aaram karne laga, 1 ka wait kar rha 
5) 1 check hua 1==1 ho gya ,iska answer true mila bola 2 ko ki malik true hi iska answer ab 2 utha usne apne malik ko bola ki 4 iska answer true hi
   4 ne apne malik 8 ko bola iska answer true hi 8 bola apne malik 16 ko iska answer true hi 16 ne raja(main) ko bola iska answer true hi 
*/
bool isPrime(int n){
  if(n == 1)
    return true;
  return isPower(n/2);
}
