#include<iostream>
#include<fstream>   //used for file handling
#include<string>  
#define N 50000  //used for strings
using namespace std;

/*Everytime before running this program delete previously created 'Student_data.csv' file to avoid buffer overflow errors*/

int main()
{
    int* a1 = new int[N];
    int* a2 = new int[N];
    int* a3 = new int[N];
    int* a4 = new int[N];
    int* a5 = new int[N];
    int* a6 = new int[N];
    int* a7 = new int[N];
   //int students[8000000];
   for(int i=0;i<N;i++){
      a1[i]=rand()%5; 
      a2[i]=rand()%5; 
      a3[i]=rand()%5; 
      a4[i]=rand()%5; 
      a5[i]=rand()%5; 
      a6[i]=rand()%5; 
      a7[i]=rand()%5; 
      //cout<<students[i];//Generate number between 0 to 5
   }
    
    fstream fout;
    
    // opening an existing csv file or creating a new csv file
    fout.open("5Mdata.txt", ios::out);
    //fout<<"a1"<<" "<<"a2"<<" "<<"a3"<<" "<<"a4"<<" "<<"a5"<<" "<<"a6"<<" "<<"a7"<<"\n";
    
    
    for(int i=0; i<N; i++)
    {
        
        fout<<a1[i]<<" "<<a2[i]<<" "<<a3[i]<<" "<<a4[i]<<" "<<a5[i]<<" "<<a6[i]<<" "<<a7[i]<<"\n";   // writing data to a csv file
    }
    fout.close();   // closing csv file

    
    return 0;
}
