/*
Q.  Write a program to perform matrix multiplication using user-defined matrix object.
*/


#include<iostream>
using namespace std;

class matrix
{
    int a[10][10];
    int m,n;
    public:
    void input();
    void output();
    void multiply(matrix,matrix);
};
void matrix::input(){
    cout<<"Enter the number of row : ";
    cin>>m;
    cout<<"Enter the number of column : ";
    cin>>n;
    cout<<"Matrix"<<"\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}
void matrix :: output()
{
    for(int i=0;i<m;i++){
        cout<<"\n";
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
    }
}
void matrix :: multiply(matrix m1, matrix m2){
    if(m1.n!=m2.m) cout<<"matrix multiplication is not possible";
    else{
        for(int i=0;i<m1.m;i++){
            for(int j=0;j<m2.n;j++){
                a[i][j]=0;
                for(int k=0;k<m1.n;k++){
                    a[i][j]=a[i][j] +( m1.a[i][k]*m2.a[k][j]);
                    m=m1.m;
                    n=m2.n;
                }
            }
        }
    }
}
int main()
{
    matrix m1,m2,m3;
    m1.input();
    m2.input();
    m3.multiply(m1,m2);
    m3.output();
    cout << "\n\n"
    cout << "Lakshay Sharma :: 02396402721"
    return 0;
}
