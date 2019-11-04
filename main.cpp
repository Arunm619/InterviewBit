#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<int> wave(vector<int> A) {
    bool flag = true;
    for(int i= 0; i < A.size()-1; i++)
    {
        if(flag){
            if(A[i]<A[i+1])
                swap(A[i],A[i+1]);
            flag = false;
        }
        else{
            if(A[i]>A[i+1])
                swap(A[i],A[i+1]);
            flag = true;
        }

        //flag = !flag;
    }
    return A;
}



int main() {
    for(auto& i : wave({5,1,3,2,4})){
        cout<< i<< " ";
    }

    return 0;
}