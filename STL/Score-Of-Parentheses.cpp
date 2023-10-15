#include <iostream>
#include <stack>

using namespace std;

int scoreOfParentheses(const string &str) {
    // Each integer represents sum added to this parent parentheses
    stack<int> st;

    // Temp value to help us
    st.push(0);

    for (auto c: str) {
        if (c == '(') {
            st.push(0);     // New parent: current sum = 0
        } else {
            // An expression will be closed
            // Find its value: either 1 for empty or 2 * its sub-expressions
            // Add the expression sum to its parent current sum
            int last = st.top();
            st.pop();

            if (last == 0)
                last = 1;     // case ()
            else
                last = 2;     // case (A). Get current sum and multiply

            // Assume we have expression E that is (CHD)
            // where C, H, D are valid-subexpressions with values 5, 10, 4
            // then E is (5+10+4) = (19) = 38
            // Every time we finish an expression, we add its value to its parent

            // get the parent and update its sum with a finished sub-expression
            int parent_par = st.top() + last;    // new total sum
            st.pop();
            st.push(parent_par);
        }
    }
    return st.top();
}

int main() {
    cout << scoreOfParentheses("(()(()))(()(()))");    // 12
    return 0;
}

/*

Let's parse
				(()(()))(()(()))		Stack: 0  			[initial]
(				 ()(()))(()(()))    	Stack: 0, 0			[if ( just add 0: root value for this new (something)
((				  )(()))(()(()))    	Stack: 0, 0, 0
(()				   (()))(()(()))    	Stack: 0, 1			[if ) and last = 0, it means empty (), so we know its value is 1. Add to its parent
(()(				()))(()(()))    	Stack: 0, 1, 0
(()((				 )))(()(()))    	Stack: 0, 1, 0, 0
(()(()				  ))(()(()))    	Stack: 0, 1, 1		[3 = 2 * 1 + 1]
(()(())				   )(()(()))    	Stack: 0, 3			[6 = 2 * 3 + 0]
(()(()))			    (()(()))    	Stack: 6  			[observe single item again; complete sub-expression done]

The remaining does the same and end with 6 + 6 = 12



 */