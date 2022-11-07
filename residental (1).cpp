 #include"residental.h"
 int residential::availableWorkers = 0;  
 void residential::updated(vector<node> arr[],node** input,int i){
        int population;
        int rows;
        int col;
        int count1=0;
        int count2=0;
        int count3=0;
        int count4=0;
       
       
                    population=arr[i][0].population;
                    rows= arr[i][0].rowIndex;
                    col= arr[i][0].columnIndex;
                    
                    for(int j=1;j<arr[i].size();j++){  
                   
                         if(arr[i][j].symbol=='#'&& population==0){
                             if(arr[i][j].symbol=='#'){
                                arr[i][0].population=1;
                                input[rows][col].population=1;
                            }
                          else if(arr[i][j].population=1&&population==0){
                                count1++;
                                arr[i][0].population=arr[i][0].population+1;
                                input[rows][col].population= input[rows][col].population+1;
                                
                            }
                            availableWorkers=availableWorkers+1;
                            
                         }
                         else if( population==0){
                             if(arr[i][j].population==1)
                                count1++;
                             if(count1==1){
                                arr[i][0].population=arr[i][0].population+1;
                                input[rows][col].population= input[rows][col].population+1;
                                availableWorkers=availableWorkers+1;
                             }
                         }
                          else if(population==1){
                            if(arr[i][j].population==1) 
                             count1++;
                             if(count1==2){
                             arr[i][0].population=arr[i][0].population+1;
                             input[rows][col].population= input[rows][col].population+1;
                             availableWorkers=availableWorkers+1;
                             }
                         }
                          else if(population==2){
                             if(arr[i][j].population==2)
                                count2++;
                             if(count2==4){
                                arr[i][0].population=arr[i][0].population+1;
                                input[rows][col].population= input[rows][col].population+1;
                                availableWorkers=availableWorkers+1;
                             }
                         }
                         else if(population==3){
                            if(arr[i][j].population==3)
                                count3++;
                            if(count3==6){
                                arr[i][0].population=arr[i][0].population+1;
                                input[rows][col].population= input[rows][col].population+1;
                                availableWorkers=availableWorkers+1;
                            }
                         }
                          else if(population==4){
                             if(arr[i][j].population==4)
                                count4++;
                             if(count4==8){
                                arr[i][0].population=arr[i][0].population+1;
                                input[rows][col].population= input[rows][col].population+1;
                                availableWorkers=availableWorkers+1;
                             }
                         }
                         
                    }
                
                
                
        
    }