#include <stdio.h>
#include <malloc.h>

int main()
{
        int n, i, j;
        float key;

        FILE *fin, *fout;
        fin = fopen("sortland.in", "r");
        fout = fopen("sortland.out", "w");
        
        fscanf (fin, "%d", &n);
        float *a, *b;
        a, b = (float*)malloc(n * sizeof(float));
        for (i = 0; i < n; ++i ) {
            fscanf(fin, "%f", &a[i]);
            b[i] = a[i];
        }

        for (i = 1; i < n; ++i) {
            key = b[i];
            j = i-1;
            while (b[j] > key && j >= 0) {
                b[j+1] = b[j];
                --j;
            }
            b[j+1] = key;
        }

        int max;
        
        for ( i = 0 ; i < n ; ++i) {
            if (a[i] == b[n-1]) {
                max = i + 1;
            }
        }

        fprint (fout, "%d", max);

        free(a);
        free(b);
        fclose(fin);
        fclose(fout);
        return 0;
    
}