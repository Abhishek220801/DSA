int main(){

    int array[]={1,2,3,4,5};
    int n = sizeof(array)/sizeof(array[0]);

    //for loop
    for(int i=0;i<n;i++){
        cout<<array[i]<<endl;
    }

    //for each loop
    for(int ele:array){
        cout<<ele<<endl;
    }

    //while loop
    int i=0;
    while(i<n){
        cout<<array[i]<<endl;
        i++;
    }

    return 0;
}
