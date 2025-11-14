int secondMax(int arr[], int n){
    int mx, secondMax=-1, maxIdx=-1;
    mx = secondMax = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>mx){
            mx = arr[i];
            maxIdx = i;
        }
    }
    arr[maxIdx] = -1;
    
    for(int i=0; i<n; i++){
        if(arr[i]>secondMax && arr[i]!=mx){
            secondMax = arr[i];
        }
    }
    return secondMax;
}

//OR

int secondLargestElement(int arr[],int n){
    int max = INT_MIN;
    int second_max = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }

    for(int i=0;i<n;i++)
        if(arr[i]>second_max && arr[i]!=max) second_max=arr[i];
    }

    return second_max;
}

//OR

https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int ans = -1;
	    
	    //largest element 
	    for(int i=0;i<n;i++){
	        if(arr[i]>ans)
	            ans = arr[i];
	    }
	    
	    //second largest
	    int second = -1;
	    for(int i=0;i<n;i++){
	        if(arr[i]!=ans){
	            second = max(second, arr[i]);
	        }
	    }
	    
	    return second;
	}
};

//OR

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0], slargest = -1;
        for(int i=0;i<n;i++){
            if(arr[i]>largest){
                slargest = largest;
                largest = arr[i];
            }
            else if(arr[i]<largest && arr[i]>slargest){
                slargest = arr[i];
            }
        }
        return slargest;
    }
};

