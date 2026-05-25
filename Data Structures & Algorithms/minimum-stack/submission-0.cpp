class MinStack {
public:
    stack<int>s1;
    stack<int>s2;

    MinStack() {
        
    }
    
    void push(int val) {
       
        s1.push(val);
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        int min = INT_MAX;
       while(!s1.empty()){
        s2.push(s1.top());
        if(s1.top() < min){
            min = s1.top();
        }
        s1.pop();
       }
       while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
       }

       return min;
    }
};
