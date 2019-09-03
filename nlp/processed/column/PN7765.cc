#include <cstdlib>
#include <stdio.h>
typedef unsigned short word;
typedef unsigned long long int qword;
const int MAX=10000001;
struct tx
{
    word h;
    int l,r;
};
word s[MAX];
tx x[MAX];
int j,k,m,ns,nx,l0,l,r0,r;
qword v;
void add(int j, int k)
{
    int l,m;
    word h;
    if(x[j].h<x[k].h) h=x[j].h; else h=x[k].h;
    if(x[j].r<x[k].l) for(l=x[j].r+1;l<x[k].l;l++) v+=h-s[l];
    else for(l=x[k].r+1;l<x[j].l;l++) v+=h-s[l];
}
bool lt(tx y, tx z) { return y.h<z.h||(y.h==z.h&&y.l<z.l); }
void QSort(int l, int r)
{
    tx y,z;
    int i,j;
    z=x[l+rand()%(r-l+1)];
    i=l;
    j=r;
    while(i<=j)
    {
        while(lt(x[i],z)) i++;
        while(lt(z,x[j])) j--;
        if(i<=j) { y=x[i]; x[i]=x[j]; x[j]=y; i++; j--; }
    }
    if(l<j) QSort(l,j);
    if(i<r) QSort(i,r);
}
int main()
{
    scanf("%d", &ns);
    for(j=1;j<=ns;j++) scanf("%d", &s[j]);
    nx=1;
    x[1].h=s[1];
    x[1].l=x[1].r=1;
    for(j=2;j<=ns;j++)
        if(s[j-1]<s[j])
        {
            x[nx].h=s[j];
            x[nx].l=x[nx].r=j;
        }
        else if(s[j-1]==s[j]) x[nx].r=j; else nx++;
    if(x[nx].h==0) nx--;
    if(nx<=1) printf("0\n");
    else
    {
        QSort(1,nx);
        v=0;
        add(nx,nx-1);
        if(x[nx].r<x[j].l) { l0=nx; r0=nx-1; }
        else { r0=nx; l0=nx-1; }
        l=nx-1;
        do
        {
            do l--; while(!(l==0||x[l].r<x[l0].l));
            if(l>0) { add(l0, l); l0=l; }
        } while(l!=0);
        r=nx-1;
        do
        {
            do r--; while(!(r==0||x[r].r>x[r0].r));
            if(r>0) { add(r0,r); r0=r;}
        } while(l!=0);
        printf("%d\n", v);
    }
    return 0;
}
