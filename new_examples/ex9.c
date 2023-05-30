#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    int e,f,g;
    double k;
    
    double area[n];
    for(int x = 0;x<n;x++){
        double p = (float)(tr[x].a + tr[x].b+tr[x].c)/2;
        area[x] = sqrt(p*(p-tr[x].a)*(p-tr[x].b)*(p-tr[x].c));
    }
    for(int y = 0; y < n ; y++){
        for(int z = y+1 ; z < n ; z++ ){
            if(area[y]>area[z])
            {   
                k = area[y];
                area[y] = area[z];
                area[z] = k;
                //printf(".....%lf %lf",area[z],area[y]);
                e = tr[y].a;
                f = tr[y].b;
                g = tr[y].c;
                tr[y].a = tr[z].a;
                tr[y].b = tr[z].b;
                tr[y].c = tr[z].c;
                tr[z].a = e;
                tr[z].b = f;
                tr[z].c = g;
                
            }
        }
    }
   //for (int i = 0; i < n; i++) {
		//printf("..... %d %d %d\n", tr[i].a, tr[i].b, tr[i].c);}
}
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
    printf("HELLO\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}