#include <iostream>
//#include <iostream.h>

using namespace std;

void Stoking_R(int start, bool stok);
void Stoking_L(int start, bool stok);

long long Total = 0;
//__int64 Total = 0;
int     N,  *A, *Water, *Stok, iStok = -1, Max = -1;

int main()
{
int i;

cin >> N;
A = new int [N]; Stok = new int [N]; Water = new int [N];
for(i = 0; i < N; i++)
 {
  cin >> *(A + i);
  if(*(A + i) > Max) Max = *(A + i);
  if(*(A + i) == 0) { iStok++; *(Stok + iStok) = i; }
 }
if(Max == 0) { cout << Total; return 0; }
for(i = 0; i < N; i++) *(Water + i) = Max - *(A + i);
Stoking_R(0, false); Stoking_L(N - 1, false);
for(i = 0; i <= iStok; i++)
  { Stoking_R(*(Stok + i), true); Stoking_L(*(Stok + i), true); }
for(i = 0; i < N; i++) Total += *(Water + i);
cout << Total;
delete [] A; delete [] Stok; delete [] Water;
return 0;
}
//-----------------------------------------------------------------------------
void Stoking_R(int start, bool stok)
{
int i, knife = Max;

if(stok) { *(Water + start) = 0; start++; }
for(i = start; i < N; i++)
 {
  if(*(Water + i) == 0) break;
  if(knife >= *(Water + i)) { knife = *(Water + i); *(Water + i) = 0; }
  else                        *(Water + i) -= knife;
 }
}
//-----------------------------------------------------------------------------
void Stoking_L(int start, bool stok)
{
int i, knife = Max;

if(stok) { *(Water + start) = 0; start--; }
for(i = start; i >= 0; i--)
 {
  if(*(Water + i) == 0) break;
  if(knife >= *(Water + i)) { knife = *(Water + i); *(Water + i) = 0; }
  else                        *(Water + i) -= knife;
 }
}
//-----------------------------------------------------------------------------








