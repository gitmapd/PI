    #include <stdio.h>
    void reverte(int a[], int start, int end) {

        while(start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
        }
    }

    void rodaEsq(int a[],int N,int r ) {
        if(r <=0 || r >= N) return;
    reverte(a,0,r-1);
    reverte(a,r,N-1);
    reverte(a,0,N-1);
    }

    void rodaDir(int a[],int N, int r) {
        if(r <= 0 || r >= N) return;
    reverte(a,N-r ,N-1);
    reverte(a,0,N-r-1);
    reverte(a,0,N-1);
        
    }
    int main() {
    int r = 2;
    int a[]={1, 2, 3, 4, 5, 6};
    int b[]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);

    rodaEsq(a,6,2);

    for (int i = 0; i < size_a;i++) {
        printf("%d\n",a[i]);
    }
    rodaDir(b,10,2);


    for (int i = 0; i < size_b;i++) {
        printf("%d\n",b[i]);
    }
    }

    