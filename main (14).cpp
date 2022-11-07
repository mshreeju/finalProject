/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
#include<vector>
#include<fstream>

#include"industrial.h"
#include"commercial.h"

using namespace std;

//to output the results
void output(node** input,int row,int col,residential r,industrial I){
    
    for (int i = 0; i < row; i++) {
       
      for (int j = 0; j < col; j++){  
	    if(input[i][j].population==0){
	        cout << input[i][j].symbol;
	       
	    }
	    else{
	        cout<<input[i][j].population;
	        
	       
	    }
	    if(j!=col-1)
	    cout<<",";
	        
	}
	cout<<endl;
	
    }
   // cout<<endl;
    cout<<"Total available workers "<<r.availableWorkers<<endl;
    cout<<"Total available goods "<<I.availableGoods<<endl;
    cout<<endl<<endl;
    
}

void addNeighbour(vector<node> arr[],node** input,int row,int col){
int index=0;
  for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
          if(input[i][j].symbol=='R'||input[i][j].symbol=='C'||input[i][j].symbol=='I'){
              if(j==0){
                  arr[index].push_back(input[i][j]);
                  
                  if(i==0){
                      
                      arr[index].push_back(input[i][j+1]);
                      arr[index].push_back(input[i+1][j]);
                      arr[index].push_back(input[i+1][j+1]);
                      
                  }
                  else if(i==row-1){
                      
                      arr[index].push_back(input[i][j+1]);
                      arr[index].push_back(input[i-1][j]);
                      arr[index].push_back(input[i-1][j+1]);
                  }
                  else{
                      
                      arr[index].push_back(input[i][j+1]);
                      arr[index].push_back(input[i+1][j]);
                      arr[index].push_back(input[i+1][j+1]);
                      arr[index].push_back(input[i-1][j]);
                      arr[index].push_back(input[i-1][j+1]);
                      
                  }
                  
              }
              else if(j==col-1){
                  arr[index].push_back(input[i][j]);
                  if(i==0){
                      arr[index].push_back(input[i][j-1]);
                      arr[index].push_back(input[i+1][j]);
                      arr[index].push_back(input[i+1][j-1]);
                      
                  }
                  else if(i==row-1){
                      arr[index].push_back(input[i-1][j]);
                      arr[index].push_back(input[i-1][j-1]);
                      arr[index].push_back(input[i][j-1]);
                  }
                  else{
                      arr[index].push_back(input[i][j-1]);
                      arr[index].push_back(input[i-1][j-1]);
                      arr[index].push_back(input[i-1][j]);
                      arr[index].push_back(input[i+1][j]);
                      arr[index].push_back(input[i+1][j-1]);
                  }
              }
              else if(j>0&&j<col-1&&i!=0&&i!=row-1){
                  
                  arr[index].push_back(input[i][j]);
                  arr[index].push_back(input[i][j+1]);
                  arr[index].push_back(input[i][j-1]);
                  arr[index].push_back(input[i-1][j-1]);
                  arr[index].push_back(input[i-1][j]);
                  arr[index].push_back(input[i-1][j+1]);
                  arr[index].push_back(input[i+1][j-1]);
                  arr[index].push_back(input[i+1][j]);
                  arr[index].push_back(input[i+1][j+1]);
                  
              }
              index++;
          }
          else
            continue;
          
      }
  }
  }
  

int main ()
{
int workers1,workers2,goods1,goods2;
int record=0;//to track records of how many times does value of available goods and workers come same 
char inputComma;//to get data from file 
int timeValue=0;//To compare value of time limit and time value
node x;
  //to push the node in vector
  residential R;
  commercial C;
  industrial I;
  int row,col;
  int index;//to count total number of value in array required
  string extra;//to read extra string from config1 file
  string fileName;//to read file Name from user
  string csvFile;//to read csv file from config1 file
  int timeLimit;//to read timelimit from config1 file
  int refRate;//to read refresh rate from file
  
  // configuration file opening
  ifstream fileOpen;
  cout<<"Enter the configuration file that you want to open: ";
  cin>>fileName;
  fileOpen.open(fileName);
  if(fileOpen.fail()){
      cout<<"Cannot open the file"<<endl;
      exit(0);
  }
  while(!fileOpen.eof()){
      getline(fileOpen,extra,':');
      getline(fileOpen,csvFile);
      fileOpen.ignore();
      getline(fileOpen,extra,':');
      fileOpen>>timeLimit;
      fileOpen.ignore();
      getline(fileOpen,extra,':');
      fileOpen>>refRate;
  }
  fileOpen.close();
  
  cout<<"How many rows of data you got in region layout file(have 5 rows on layout file)"<<endl;
  cin>>row;
  cout<<"How many columns of data you got in region layout file(have six columns on layout file)"<<endl;
  cin>>col;
  int value=0;//To find out an index of an array and pass it to the functions
  
 /* where 0 represents industrial 1 represents commercial 2 represents residential 3 represents residential
     4 represents powerline 5 represents powerline over road 6 represents powerplant */
      node** input = new node*[row];
 
    for (int i = 0; i < row; i++) {
 
        // Declare a memory block
        // of size n
        input[i] = new node[col];
        
    }
 
  
  ifstream fin;
  fin.open (csvFile);
  if (fin.fail ())
    {
      cout << "Cannot open file" << endl;
      exit (0);
    }

      for (int i = 0; i < row; i++){
	    for (int j = 0; j < col; j++){
	      fin >> input[i][j].symbol;
	      fin >> inputComma;
	      input[i][j].rowIndex = i;
	      input[i][j].columnIndex = j;
	      input[i][j].population = 0;
	      if(input[i][j].symbol=='R'||input[i][j].symbol=='C'||input[i][j].symbol=='I'){
	        value++;
	        
	      }
	   }
	    }
vector < node > arr[value];//creating an array to store neighbours of residential,commericial and industrial
 
 
  //Inserting neighbouring elements of residential,industrial,commercial
addNeighbour(arr, input,row,col);
  
do{
    index=0;
for(int i=0;i<row;i++){
     for(int j=0;j<col;j++){
        if(input[i][j].symbol=='R'||input[i][j].symbol=='C'||input[i][j].symbol=='I'){
        workers1=R.availableWorkers;
        goods1=I.availableGoods;

         if(input[i][j].symbol=='R'){
             
            R.updated(arr,input,index);
         }
            
         else if(input[i][j].symbol=='C'){
             
             C.updated(arr,input,index);
         }
            
         else{
             
             I.updated(arr,input,index);
            
         }
         index++;
         workers2=R.availableWorkers;
         goods2=I.availableGoods;
         if((workers1==workers2)&&(goods1==goods2))
             record++;
        if((workers1!=workers2)||(goods1!=goods2))
            record=0;
        if(record==3)
            break;
             
         output(input,row,col, R,I);
         
        }
        
        else 
            continue;
     }
     if(record==3)
 break;
     
 }
 timeValue++;
 if(record==3)
 break;
}

while(timeValue!=timeLimit);

fin.close ();
for (int i = 0; i < row; i++){ // To delete the inner
                                // arrays
        delete[] input[i];
    delete[] input; // To delete the outer array
                // which contained the pointers
                // of all the inner arrays
 
    return 0;
}
  
   

}
