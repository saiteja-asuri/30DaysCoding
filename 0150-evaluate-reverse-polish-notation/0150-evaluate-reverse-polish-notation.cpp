class Solution {
public:
    int calResult(long &a,long &b,string &s)
    {
        if(s=="+")
            return a+b;
        else if(s=="-")
            return b-a;
        else if(s=="*")
            return a*b;
        else
            return b/a;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        unordered_set<string> ust({"+","*","-","/"});
        for(int i=0;i<tokens.size();i++)
        {
            if(ust.count(tokens[i])==0)
            {
                st.push(tokens[i]);
            }
            else
            {
                long op1=stoi(st.top());
                st.pop();
                long op2=stoi(st.top());
                st.pop();
                long res=calResult(op1,op2,tokens[i]);
                st.push(to_string(res));
            }
        }
        return stoi(st.top());
    }
};