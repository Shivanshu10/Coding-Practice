#include<bits/stdc++.h>

using namespace std;

class Time
{
    private:
        int hr;
        int mins;
    public:
        Time(int h, int m) {
            hr=h; mins=m;
        }
        static Time timeFromStr(string t) {
            string h, m;
            bool has_pm=false, twelve_am=false, twelve_pm=false;
            if (t.find("PM") != std::string::npos) {
                has_pm=true;
                if ((t.substr(0,2).find("12") != std::string::npos )) {
                    twelve_pm=true;
                }
            }
            if (t.find("AM") != std::string::npos && (t.substr(0,2).find("12") != std::string::npos )) {
                twelve_am=true;
            }
            h=t.substr(0, 2);
            m=t.substr(3, 2);
            stringstream hour(h);
            stringstream miniutes(m);
            int hours, minus;
            hour >> hours;
            miniutes >> minus;
            if (has_pm && !twelve_pm) {
                hours+=12;
            }
            if (twelve_am) {
                hours=0;
            }
            return Time(hours, minus);
        }
        int hour() {
            return hr;
        }
        int minutes() {
            return mins;
        }
        bool operator>=(Time& t) {
            if (t.hour() == this->hour()) {
                if (t.minutes() <= this->minutes()) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else if (t.hour() < this->hour()) {
                return true;
            }
            else {
                return false;
            }
        }
        bool operator<=(Time &t) {
            if (t.hour() == this->hour()) {
                if (t.minutes() >= this->minutes()) {
                    return true;
                }
                return false;
            }
            else if (t.hour() > this->hour()) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string p, temp, temp1, temp2;
    int test_cases, n;
    cin >> test_cases;
    string *out = new string[test_cases];
    //string *arr[2];
    //cin >> test_cases;
    //getchar();
    cin.ignore();
    for (int i=0; i<test_cases; i++) {
        getline(cin, p, '\n');
        Time meet = Time::timeFromStr(p);
        cin >> n;
        //arr[0]=new string[n];
        //arr[1]=new string[n];
        cin.ignore();
        //getchar();
        for (int j=0; j<n; j++) {
            //cin.ignore();
            getline(cin, temp, '\n');
            temp1=temp.substr(0, 8);
            //arr[0][j]=temp;
            Time t1=Time::timeFromStr(temp1);
            //getline(cin, temp);
            temp2=temp.substr(9, 8);
            //arr[1][j]=temp;
            Time t2=Time::timeFromStr(temp2);
            if (t1<=meet && t2>=meet) {
                out[i]+="1";
            }
            else {
                out[i]+="0";
            }
        }
    }
    for (int i=0; i<test_cases; i++) {
        cout << out[i] << endl;
    }
    return 0;
}