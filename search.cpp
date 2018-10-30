#include <iostream>
using namespace std;

template <class T>
class search{
	T *arr;
	int size;
	public:
		search();
		int FibonacciSearch(T ele);
		int BinarySearch(T ele);
};
template <typename T>
search<T> :: search(){
	cout << "Enter Number of Elements : ";
	cin >> size;
	cout << "Enter Elements : ";
	arr = new T[size];
	for(int i = 0 ; i < size ; i++){
		cin >> arr[i];
	}
}

template <typename T>
int search<T> :: FibonacciSearch(T ele){
	int Fib2 = 0;
	int Fib1 = 1;
	int Fib = 1;
	while(Fib < size){
		Fib2 = Fib1;
		Fib1 = Fib;
		Fib = Fib1 + Fib2;
	}
	int offset = -1;
	while(Fib > 1){
		int i = min(offset + Fib2 , size - 1);
		if(arr[i] < ele){
			//move One Fibonacci Down
			Fib = Fib1;
			Fib1 = Fib2;
			Fib2 = Fib - Fib1;
			offset = i;	// change the offset			
		}
		else if(arr[i] > ele){
			//move Two Fibonacci Down
			Fib = Fib2;
			Fib1 = Fib1 - Fib2;
			Fib2 = Fib - Fib1;
		}
		else return i;
	}
	if(arr[offset + 1] == ele and Fib1)return offset;
	return -1;
};

template <typename T>
int search<T> :: BinarySearch(T ele){
	int low = 0;
	int high = size - 1;
	while(low <= high){
		int mid = (low + high) / 2;
		if(arr[mid] == ele){
			return mid;
		}
		else if(arr[mid] < ele){
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return -1;
}

int main(){
	int queries ;
	search<int> obj;
	cout << "Enter Number of Queries :> ";
	cin >> queries;
	int ele;
	for(int i = 0 ; i < queries ; i++){
		cin >> ele;
		int getbin = obj.BinarySearch(ele);
		int getfib = obj.FibonacciSearch(ele); 
		if(getbin == -1 or getfib == -1){
			cout << "Not Found \n";
		}
		else cout << "Found at Position " << getbin + 1 << endl;
	}
	return 0;
}
