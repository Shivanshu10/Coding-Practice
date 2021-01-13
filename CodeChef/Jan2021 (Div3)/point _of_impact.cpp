#include<bits/stdc++.h>

using namespace std;

int main() {
    int test_cases;
    long size, steps, x, y, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, h, b, p4_x, p4_y;
    cin >> test_cases;
    int **out=new int*[test_cases];
    for (int i=0; i<test_cases; i++) {
        p1_x=0;
        p2_x=0;
        p3_x=0;
        p4_x=0;
        p1_y=0;
        p2_y=0;
        p3_y=0;
        p4_y=0;
        h=0;
        b=0;
        cin >> size;
        cin >> steps;
        cin >> x;
        cin >> y;
        steps=steps%4;
        if (x==y) {
            out[i]=new int[2];
            out[i][0]=size;
            out[i][1]=size;
            continue;
        }
        else if (x==size && y==0) {
            out[i]=new int[2];
            out[i][0]=x;
            out[i][1]=y;
            continue;
        }
        else if (x==0 && y==size) {
            out[i]=new int[2];
            out[i][0]=x;
            out[i][1]=y;
            continue;
        }
        else if (x!=0 || y!=0) {
            if (x<y) {
                p1_x=x-x;    
                p1_y=y-x;
            }
            else {
                p1_x=x-y;
                p1_y=y-y;
            }
        }
        if (p1_x!=0) {
            b=size-p1_x;
            h=p1_x;
            p2_x=p1_x+b;
            p2_y=b;
            p3_x=p2_x-h;
            p3_y=p2_y+h;
            p4_x=p3_x-b;
            p4_y=p3_y-b;
        }
        else if (p1_y!=0) {
            b=size-p1_y;
            h=p1_y;
            p2_x=b;
            p2_y=b+p1_y;
            p3_x=p2_x+h;
            p3_y=p2_y-h;
            p4_x=p3_x-b;
            p4_y=p3_y-b;
        }
        if (y==size || x==size) {
            p2_x=p3_x;
            p2_y=p3_y;
            p3_x=p4_x;
            p3_y=p4_y;
            p4_x=p1_x;
            p4_y=p1_y;
            p1_x=x;
            p1_y=y;
        }
        if (steps==0) {
            out[i]=new int[2];
            out[i][0]=p1_x;
            out[i][1]=p1_y;
        }
        else if (steps==1) {
            out[i]=new int[2];
            out[i][0]=p2_x;
            out[i][1]=p2_y;
        }
        else if (steps==2) {
            out[i]=new int[2];
            out[i][0]=p3_x;
            out[i][1]=p3_y;
        }
        else {
            out[i]=new int[2];
            out[i][0]=p4_x;
            out[i][1]=p4_y;
        }
    }
    for (int i=0; i<test_cases; i++) {
        cout << out[i][0] << " ";
        cout << out[i][1] << " ";
        cout << endl;
    }
    return 0;
}