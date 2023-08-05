#include <iostream>
using namespace std;

int comparisions=0;
int partition(int arr[], int p, int r){
	// generating the random index and swapping with last element(pivot)
	int randomIndex=rand()%(r-p+1)+p;
	swap(arr[randomIndex],arr[r]);
	int pivot=arr[r];
	int j=p-1;
	for(int i=p;i<r;i++){
    	// getting all the elements smaller than pivot on left side
    	if(pivot>=arr[i]){
        	swap(arr[i],arr[++j]);
    	}
	}
	swap(arr[j+1],arr[r]);
	return j+1;
}

void quickSort(int arr[], int p, int r){
	if(p<r){
    	int q=partition(arr,p,r);
    	quickSort(arr,p,q-1);
    	comparisions+=(q-1)-p+1;
    	quickSort(arr,q+1,r);
    	comparisions+=(q+1)-r+1;
	}
}

int main() {
	srand(time(NULL));  //seeding for getting random numbers after every execution
	int n;
	cin>>n;
	int arr[n];
	for(int& i:arr) cin>>i;
	quickSort(arr,0,n-1);
	for(int i:arr) cout<<i<<" ";
	cout<<endl<<comparisions<<endl;
    return 0;
}
