#include"industrial.h"
int industrial::availableGoods=0;
void industrial:: updated(vector<node> arr[],node** input,int i){
     int population;
        int rows;
        int col;
        int count1=0;
        
     
                    population=arr[i][0].population;
                    rows= arr[i][0].rowIndex;
                    col= arr[i][0].columnIndex;
                    
                    for(int j=1;j<arr[i].size();j++){  
                            
                         if(arr[i][j].symbol=='#'&& r.availableWorkers>=2  && population==0){
                            arr[i][0].population=1;
                            input[rows][col].population=1;
                            r.availableWorkers=r.availableWorkers-1;
                             availableGoods=availableGoods+1;
                        }
                         else if(arr[i][j].population>=1 && r.availableWorkers>=1  && population==0){
                             count1++;
                             arr[i][0].population=arr[i][0].population+1;
                             input[rows][col].population= input[rows][col].population+1;
                             r.availableWorkers=r.availableWorkers-1;
                             availableGoods=availableGoods+1;
                         }
                         else if(population==1){
                             if(arr[i][j].population>=1)
                             count1++;
                             if(count1>=2&&r.availableWorkers>=2){
                                arr[i][0].population=arr[i][0].population+1;
                                input[rows][col].population= input[rows][col].population+1;
                                r.availableWorkers=r.availableWorkers-1;
                                availableGoods=availableGoods+1;
                             }
                         }
                        else if(population==2){
                            if(arr[i][j].population>=2)
                             count1++;
                             if(count1>=4&&r.availableWorkers>=2){
                                arr[i][0].population=arr[i][0].population+1;
                                input[rows][col].population= input[rows][col].population+1;
                                r.availableWorkers=r.availableWorkers-1;
                                availableGoods=availableGoods+1;
                             }
                         }
                         
                         
                    }
                
                
                
}