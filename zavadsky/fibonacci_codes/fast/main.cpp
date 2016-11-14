#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int block_size = 8;
const int M = 148;
const int wcount = 5*1e6;
const int numShifts = 20;
vector<int> fib3, start;

struct entry {
    short PL, PV, SL, SV, p;
    vector<int> S;
};

int getIndex(int n, int l) {
    int ans = start[l];
    for (int i = l - 1; i >= 0; i--)
        if (n & 1 << i)
            ans += fib3[l - 1 - i];
    return ans;
}

int f2(int n,int l) {
    if (l < 0)
        return M - l;
    return getIndex(n, l) - start[l];
}

entry** build_partial_decoding_table() {
    entry **Table = new entry*[3];
    for (int p = 0; p < 3; p++) {
        Table[p] = new entry[1 << block_size];
        for (int i = 0; i < 1 << block_size; i++) {
            entry *Element = &Table[p][i];
            Element->PL = block_size; Element->SL = 0;
            Element->p = 0;
            int pos = 0, prefix = 0, suffix = 0;
            for (int j = block_size - 1; j >= 2; j--) {
                int match = (((1 << (j + 1)) - 1) & i) >> (j - 2);
                int match2 = i >> (block_size - 3 + p);
                if (Element->PL == block_size) {
                    if (match2 + 1 == 1 << (3 - p)) {
                        prefix = i >> (j + 1);
                        Element->PL = -p;
                        Element->PV = f2(prefix, Element->PL);
                        suffix = ((1 << (j - 2 + p)) - 1) & i;
                        Element->SL = j - 2 + p;
                        Element->SV = f2(suffix, Element->SL);
                        j -= (2 - p);
                        pos = j - 1;
                    }
                    else if (match == 7) {
                        prefix = i >> (j + 1);
                        Element->PL = block_size - j - 1;
                        Element->PV = f2(prefix, Element->PL);
                        suffix = ((1 << (j - 2)) - 1) & i;
                        Element->SL = j - 2;
                        Element->SV = f2(suffix, Element->SL);
                        j -= 2;
                        pos = j - 1;
                    }
                }
                else if (match == 7) {
                    int len = pos - j, num = (i >> (j + 1)) & ((1 << len) - 1);
                    suffix = ((1 << (j - 2)) - 1) & i;
                    Element->SL = j - 2;
                    Element->SV = f2(suffix, Element->SL);
                    Element->S.push_back(getIndex(num, len));
                    j -= 2;
                    pos = j - 1;
                }
            }
            int sf = Element->PL == block_size ? i : suffix;
            if (Element->PL == block_size)
                Element->PV = f2(i, Element->PL);
            if ((sf & 3) == 3)
                Element->p = 2;
            else if (sf & 1)
                Element->p = 1;
            /*
            cout<<i<<":\n";
            cout<< Element->PL<<" "<<Element->PV<<" "<< Element->SL<<" "<<Element->SV<<" "<<Element->p<<"\n";
            cout<<"S: ";
            for (int v: Element->S)
                cout<<v<<" ";
            cout<<"\n\n";
            */
        }
    }
    return Table;
}

int** build_Fib3() {
    fib3 = {1, 2, 4};
    start = {1, 2, 3, 5, 9};
    for (int i = 3; fib3.back() <= wcount; i++)
        fib3.push_back(fib3[i - 3] + fib3[i - 2] + fib3[i - 1]),
        start.push_back(start.back() + fib3.back());
    
    int **Table = new int*[M + 3];
    Table[0] = new int[numShifts];
    for (int shift = 0; shift < numShifts; shift++)
        Table[0][shift] = 0;
    for (int i = 1; i <= M; i++) {
        Table[i] = new int[numShifts];
        for (int f = fib3.size() - 1, j = i; f>=0; f--)
            if (j >= fib3[f]) {
                j -= fib3[f];
                for (int shift = 0; shift < numShifts && f + shift < fib3.size(); shift++)
                    Table[i][shift] = Table[j][shift] + fib3[f + shift];
                break;
            }
    }
    Table[M + 1] = new int[numShifts];
    Table[M + 2] = new int[numShifts];
    for (int j = 1; j < numShifts; j++)
        Table[M + 1][j] = -fib3[j - 1];
    for (int j = 2; j < numShifts; j++)
        Table[M + 2][j] = - fib3[j - 1] - fib3[j - 2];
    /*
    for (int i = 147; i <= 150; i++) {
        cout<<Table[i][0]<<" "<<Table[i][1]<<" "<<Table[i][2]<<" "<<Table[i][19]<<"\n";
    }
    */
    return Table;
}

int main() {
    int **Fib3 = build_Fib3();
    entry **Tab = build_partial_decoding_table();
    
    vector<int> v = {227, 221, 226, 221, 223};
    int oldSL(0), oldSV(0), p(0);
    entry e;
    for (int code: v) {
        e = Tab[p][code];
        p = e.p;
        if (e.PL == block_size) {
            oldSV += Fib3[e.PV][oldSL];
            oldSL += e.PL;
        }
        else {
            int index = oldSV + Fib3[e.PV][oldSL] + start[oldSL + e.PL];
            cout<<index<<" ";
            for (int el: e.S)
                cout<<el<<" ";
            oldSV = e.SV;
            oldSL = e.SL;
        }
    }
    cout<<"\n";
    return 0;
}
