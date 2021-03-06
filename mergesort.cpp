#include <iostream>
#include <vector>

void swap(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}
void mergesort(std::vector<int> &X, int first, int last, bool funcomp(int&,int&)){
    if((last-first) > 1){
        int middle = (last+first)/2;
        mergesort(X,first,middle,funcomp);
        mergesort(X,middle+1,last,funcomp);
        int k1=first,k2=middle+1;
        while(true){
            if(funcomp(X[k1],X[k2])){
                for(int i=k2;i>k1;i--) swap(X[i-1],X[i]);
                k1++; k2++;
            }
            else k1++;
            if(k1==k2||k2>last) break;
        }
    }
    else if((last-first)==1) if(funcomp(X[first],X[last])) swap(X[first],X[last]);
    return;
}
int main()
{
    std::vector<int> X = {7,8,5,1,4,6,2,3};
    std::cout<<"Unsorted:\n";
    for(int &elem: X)
        std::cout<<" "<<elem;
    std::cout<<"\n";
    mergesort(X,0,X.size()-1,
              [](int &x1,int &x2){
             return x1<x2;                  //descending sorting
         });
    mergesort(X,0,X.size()-1,
              [](int &x1,int &x2){
             return (x1%2==0)&&(x2%2==1);   //differentiation of odd and even numbers
         });
    std::cout<<"Sorted:\n";
    for(int &elem: X)
         std::cout<<" "<<elem;
    std::cout<<"\n";
    return EXIT_SUCCESS;
}
