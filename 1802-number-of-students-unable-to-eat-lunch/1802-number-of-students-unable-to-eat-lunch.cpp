class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> qstudents;
        queue<int> qsandwiches;
        int r=0;
        for(int i=0;i<students.size();i++){
            qstudents.push(students[i]);
        }
        for(int i=0;i<sandwiches.size();i++){
            qsandwiches.push(sandwiches[i]);
        }
        while(!qsandwiches.empty() && !qstudents.empty()){
            if(qsandwiches.front()==qstudents.front()){
                qsandwiches.pop();
                qstudents.pop();
                r=0;
            }
            else{
                int el=qstudents.front();
                qstudents.pop();
                qstudents.push(el);
                r++;
            }
            if(r==qstudents.size()){
                break;
            }
        }
        return qstudents.size();
    }
};