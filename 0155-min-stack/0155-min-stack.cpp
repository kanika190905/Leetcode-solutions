class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else if(val >= mini){
            st.push(val);
        }
        else{
            st.push(2LL * val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if(topVal < mini){
            mini = 2LL * mini - topVal;
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        if(st.top() < mini)
            return mini;   
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};
