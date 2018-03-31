int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> indices;
    A.push_back(0);
    
    int max_area = 0;
    int i=0;
    
    while(i<A.size()){
        
        if(indices.empty() || A[i] > A[indices.top()]){
            indices.push(i);
            ++i;
        }
        else{
                int top_index = indices.top();
                int height = A[top_index];
               
             // get rid of that bar by removing that index from stack and keep on popping untill A[i] is greater   
                indices.pop();
                // find the width and multiply by lowest height
                int area;
                int width;
                if(indices.empty()){
                    width = i;
                }
                else{
                    width = i - indices.top() - 1;
                }
                
                area = height*width;
                max_area = (area > max_area)? area: max_area;
                
        }
    } // the stack is assured to be empty because of last 0
    
    return max_area;
}
