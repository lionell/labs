//Column
#include <iostream>
#include <iomanip>
using namespace std;
void voda(int, int); //çàïîëíåíèå âîäîé (âûâîä ñóììû)
int pik(int); //ïîèñê ïèêà (âûâîä íîâîãî èíäåêñà)
long long S = 0;
int N;
short *M;
int main()
{
	cin >> N;
	M = new short[N];

	//èíèöèàëèçèðóåì ìàññèâ êóáèêîâ
	for (int i = 0; i < N; i++)
		cin >> M[i];
		
	int index1 = pik(0); //ïåðâûé ïèê ñ íà÷àëà ìàññèâà
	
	a:	int index2=pik(index1+1);
		if (index2 == -1)
		{
			cout << S;
			return 0;
		}
		//èùåì ïèê áîëüøèé èëè ðàâíûé íàéäåííîìó	
		while (M[index2] < M[index1] && index2!=-1) index2 = pik(index2 + 1);
		if (index2 == -1) index2 = pik(index1+1);
			
		voda(index1, index2);
		index1 = index2;
	goto a;

return 0;
}

int pik(int a) //ïîèñê ïèêà (âûâîä íîâîãî èíäåêñà)
{
	for (int i = a; i < N; i++)
		if (M[i + 1] < M[i] && M[i-1]<=M[i])
			return i;
	return -1;
}


void voda(int a, int b) //çàïîëíåíèå âîäîé (âûâîä ñóììû)
{
	int min = (M[a]<M[b]?M[a]:M[b]);
	//cout << "M[a]=" << M[a] << " M[b]=" << M[b] << "  min=" << min << endl;

	for (int i = a+1; i<b; i++)
	{
		if (M[i]<min)
		S = S + min - M[i];
		//cout << min - M[i] << "+";
	}
}