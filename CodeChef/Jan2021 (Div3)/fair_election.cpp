#include<bits/stdc++.h>  

using namespace std;

int main() {
    int test_cases, temp, temp2, total_john, total_jack, num_swap;
    cin >> test_cases;
    int *packs_num=new int[2];
    int *out=new int[test_cases];
    priority_queue <int, vector<int>, greater<int>> *john_pack=new priority_queue <int, vector<int>, greater<int>>;
    priority_queue <int> *jack_pack=NULL;
    for (int i=0; i<test_cases; i++) {
        total_jack=0;
        total_john=0;
        num_swap=0;
        john_pack=new priority_queue<int, vector<int>, greater<int>>;
        jack_pack=new priority_queue<int>;
        for (int j=0; j<2; j++) {
            cin >> packs_num[j];
        }
        for (int j=0; j<packs_num[0]; j++) {
            cin >> temp;
            total_john+=temp;
            (*john_pack).push(temp);
        }
        for (int j=0; j<packs_num[1]; j++) {
            cin >> temp;
            total_jack+=temp;
            (*jack_pack).push(temp);
        }
        while (total_john<=total_jack) {
            temp=(*john_pack).top();
            (*john_pack).pop();
            temp2=(*jack_pack).top();
            (*jack_pack).pop();
            if (temp>=temp2) {
               num_swap=-1;
                break; 
            }
            total_john-=temp;
            total_john+=temp2;
            total_jack-=temp2;
            total_jack+=temp;
            num_swap++;
            
            if (num_swap>packs_num[0]) {
                num_swap=-1;
                break;
            }
        }
        out[i]=num_swap;
        delete john_pack;
        delete jack_pack;
    }
    for (int i=0; i<test_cases; i++) {
        cout << out[i] << endl;
    }
    return 0;
}