//push opration
void push(stack<int>& st, int val){
  if(top<=size){
    st[top] = val;
    top++;
  }
  else{
    cout<<"full";
}

//pop
void pop(stack<int>& st, int val){
  if(top!=-1){
    top--;
  }
  else{
    cout<<"full";
}

//
