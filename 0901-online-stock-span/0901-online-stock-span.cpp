class StockSpanner {
    stack<pair<int,int>> s;
    int idx;
public:
    StockSpanner() {
        idx=-1;
    }
    
    int next(int price) {
        idx=idx+1;
        while(!s.empty() && price>=s.top().second){
            s.pop();
        }
        int span;
         if(s.empty()){
            span=idx+1;
        }
        else span=idx-s.top().first;

        s.push({idx,price});

        return span;
       
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */