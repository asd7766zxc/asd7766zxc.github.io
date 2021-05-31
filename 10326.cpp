

#include <iostream>
using namespace std;
int main()
{

	int n;
		cout <<"請輸入元素個數:" ;
		cin >> n ;
		cout << endl;
int a [n];
		cout << "請輸入元素:"; 

for (int i = 0 ; i < n; i++)
	cin >> a[i];

cout <<"陣列a["<<n<<"] :" ; 	
for (int i = 0 ; i < n; i++)
cout <<   a[i] << ' ';
cout << endl;



int t = 0 ;
for (int i = 1 ; i < n ; i++)
{
	for(int j = 0; j< n-i; j++)
	{
		if(a[j] < a[j+1])
	     {
	     	t = a[j];
			 a[j] = a[j+1];
			 a[j+1] = t;	
		 }
	}
}
   cout << "整理後: ";
   for(int i = 0; i < n ; i++)
   cout << a[i]<<' ';
} 
