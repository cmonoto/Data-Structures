//Jinhao Chen
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
	int k;

	int T[7] = { 7, 11, 13, 17, 19, 23, 29 };
	int h[100];
	double avg;

	srand((unsigned)time(NULL));

	cout << "Table Size" << "    " << "Avg Inserts Before Collision" << endl;
	cout << " ";
	for (int i = 0; i < 7; i++)
	{
		int j = 0;
		int sum = 0;

		while (j < 100)  // j is experiment times
		{
			bool found = false; // check in this experiment found collision or not
			for (int a = 0; a < T[i] +1 && found == false; a++)
			{
				k = rand() % 100 + 1;
				h[a] = k % T[i];
	//			  cout << k <<"%"<< T[i] << "=" << h[a] << " "; // for check list 
				for (int b = 0; b < a && found == false; b++)
				{
					if (h[b] == h[a]) // check new value h[a] equal to h[0] up to h[a-1] or not
					{                 // if it is equal return to while loop and add a to sum

						found = true;
						sum = sum + a; // sum is total value of how many numbers insert before collision
						j++;
		//				cout << endl; cout << " number before collision "<< a << "  experiment  " << j << endl <<endl; // for check a is correct and j
					}
				}


			}
		}

		avg = sum / 100.0;		
		cout << " " << T[i] << "               " << setprecision(2) << avg << "  " << endl;

	}

	cin.ignore();

}