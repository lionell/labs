#include <stdio.h>

int main()
{
	int n, max, out = 0;
    scanf ("%d", &n);
    int col [n];
    
    for (int i = 0; i < n; i++){
        scanf ("%d", &col [i]);
        if (i == 0){
            max = col [i];
        }
        if (col [i] > max){
            max = col [i];
        }
    }
    
    int ar [n][max];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < max; j++){
            if (col [i] >= max - j){
                ar [i][j] = 0;
            } else {
                ar [i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < max; j++){
            if (ar [i][j] == 1){
                int tL = 0;
                int tR = 0;
                for (int k = 0; k < i; k++){
                    if (ar [k][j] == 0){
                        tL = 1;
                    }
                }
                for (int k = i; k < n; k++){
                    if (ar [k][j] == 0){
                        tR = 1;
                    }
                }
                if (tL == 1 && tR == 1){
                    out++;
                }
            }
        }
    }
    
    printf ("%d", out);
    
	return 0;
}
