class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            string t = tokens[i];

            if (t != "+" && t != "-" && t != "*" && t != "/") {
                st.push(stoi(t));
            } else {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (t == "+")
                    st.push(a + b);
                else if (t == "-")
                    st.push(a - b);
                else if (t == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
        }

        return st.top();
    }
};