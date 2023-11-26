// C++ program to print the pattern "D"
#include <bits/stdc++.h>
using namespace std;

// Function to generate the pattern D
void D_Pattern(int n){
	
	// loop for rows
	for (int i = 0; i < n; i++){
		
		// loop for columns
		for (int j = 0; j <= n; j++){
			
			// Logic to generate stars for *
			if (j == 1 || ((i == 0 || i == n-1) &&
			(j > 1 && j < n-2)) || (j == n-2 &&
				i != 0 && i != n-1))
				cout<< "**";
				
			
			else
				cout<< "  ";
		}
		
	
	cout<< endl;
	}
}


int main()
{
int n = 9;


D_Pattern(n);
return 0;
}


