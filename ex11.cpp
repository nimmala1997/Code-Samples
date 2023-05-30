#include<iostream>
#include<vector>
using namespace std;

class Matrix {
	public :
	    // Define properties here
		int rows;
        int columns;
        vector<vector<int> > matrix;
		// Define constructor here
        Matrix(){

        }

		Matrix(int rows,int columns){
            this->rows = rows;
            this->columns = columns;
            matrix.resize(rows, vector<int>(columns));
        }
		
		void input(){
		 for(int i = 0 ; i < rows ; i++){
             for(int j = 0; j < columns ;j++){
                 cin>>matrix.at(i).at(j);
             }
         }
		}
		
		Matrix add(Matrix x){
            Matrix ans(x.rows,x.columns);
			for(int i = 0 ; i < rows ; i++){
             for(int j = 0; j < columns ;j++){
                ans.matrix.at(i).at(j) = matrix.at(i).at(j) + x.matrix.at(i).at(j);
             }
            }
            return ans;
		}
		
		Matrix subtract(Matrix x){
            Matrix ans(x.rows,x.columns);

			for(int i = 0 ; i < rows ; i++){
             for(int j = 0; j < columns ;j++){
                ans.matrix.at(i).at(j) = matrix.at(i).at(j) - x.matrix.at(i).at(j);
             }
            }

            return ans;
		}
		
		Matrix transpose(){
			Matrix ans(rows,columns);

            for(int i = 0 ; i < columns;i++){
                for(int j = 0 ; j < rows ; j++)
                    ans.matrix.at(i).push_back(matrix.at(j).at(i));
            }

            return ans;
			
		}
		
		void print(){
			for(int i = 0 ; i < rows ; i++){
             for(int j = 0; j < columns ;j++){
                 cout<<matrix.at(i).at(j);
             }
            }
			
		}
};

int main(){
   Matrix a(2, 2);  // 10 rows, 5 columns
	a.matrix.at(0).push_back(1);
    a.matrix.at(0).push_back(2);
    a.matrix.at(1).push_back(1);
    a.matrix.at(1).push_back(2);
	Matrix b(2, 2); // 10 rows, 5 columns
	b.matrix.at(0).push_back(1);
    b.matrix.at(0).push_back(2);
    b.matrix.at(1).push_back(1);
    b.matrix.at(1).push_back(2);
   Matrix c1 = a.add(b);
   Matrix c2 = a.subtract(b);
   Matrix c3 = a.transpose();
   a.print();
}
