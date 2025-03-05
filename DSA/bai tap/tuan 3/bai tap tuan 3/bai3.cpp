#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ASCII_RANGE = 256;
const int M = 15;



struct Computerinformation {
    string name;
    long speed;
    long double price;
};

void toUpper(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}

vector<Computerinformation> aux;


void insertionSort(vector<Computerinformation> &a, int lo, int hi, int d) {
    for(int i = lo; i <= hi ;i++) {
        for(int j = i; j > lo && a[j].name.substr(d) < a[j-1].name.substr(d); j--) {
            swap(a[j], a[j-1]);
        }
    }
}

void MDSSort(vector<Computerinformation> &a, int lo, int hi, int d) {
    if(hi <= lo + M) {
        insertionSort(a, lo, hi, d);
        return;
    }

    vector<int> cnt(ASCII_RANGE + 2, 0);

    for(int i = lo; i <= hi; i++) {
        int c = (d < a[i].name.length()) ? toupper(a[i].name[d]) : -1;
        cnt[c + 2]++;
    }

    for(int r = 0; r < ASCII_RANGE + 1; r++) {
        cnt[r+1] += cnt[r];
    }

    aux.resize(hi - lo + 1);

    for(int i = lo ; i <= hi; i++) {
        int c = (d < a[i].name.length()) ? toupper(a[i].name[d]) : -1;
        aux[cnt[c+1]++] = a[i];
    }

    for(int i = lo; i <= hi; i++) {
        a[i] = aux[i - lo];
    }

    for(int r = 0; r < ASCII_RANGE; r++) {
        MDSSort(a, lo + cnt[r], lo + cnt[r+1] - 1, d + 1 );
    }
}

void sortByName(vector<Computerinformation> &arr) {
    for(auto &comp : arr) {
        toUpper(comp.name);
    }
    int n = arr.size();
    aux.resize(n);
    MDSSort(arr, 0, n - 1, 0);
}

void sortBySpeed(vector<Computerinformation> &arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        Computerinformation e = arr[i]; int k;
        for(k = i - 1; k > -1; k--) {
            if(arr[k].speed > e.speed) break;
            arr[k+1] = arr[k];
        }
        arr[k+1] = e;
    }
}

void SortPrice(vector<Computerinformation> &arr) {
    int n = arr.size();
    int minn;
    for(int i = 0; i < n - 1; i++ ) {
        minn = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j].price < arr[minn].price) minn = j;
            if(arr[j].price == arr[minn].price) {
                if(arr[j].speed < arr[minn].speed) {
                    minn = j;
                }
            }
        }
        swap(arr[i], arr[minn]);
    }
}



void display(vector<Computerinformation> arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        cout <<"Brand : " << arr[i].name << endl;
        cout <<"Toc do chay : " << arr[i].speed << endl;
        cout <<"Gia tien : " << arr[i].price << endl;
	}

}

void filter(vector<Computerinformation>  arr, int p1, int p2, int s1, int s2) {
    int n = arr.size();
    vector<Computerinformation> ans;
    for(int i = 0; i < n; i++) {
        if((arr[i].price >= p1 && arr[i].price <= p2) && (arr[i].speed >= s1 && arr[i].speed <= s2)) {
            ans.push_back(arr[i]);
        }

    }
    display(ans);

}

int main()
{

vector<Computerinformation> arr = {
    {"Apple MacBook Pro", 3200, 2500.50},
    {"Dell XPS", 3000, 1800.75},
    {"ASUS ROG", 4000, 2000.99},
    {"HP Pavilion", 2800, 1400.00},
    {"Lenovo ThinkPad", 3500, 2200.00},
    {"Acer Predator", 3600, 1700.25},
    {"MSI Stealth", 3400, 2100.80},
    {"Samsung Galaxy Book", 2900, 1600.00},
    {"Gigabyte Aorus", 3100, 1900.55},
    {"Razer Blade", 3300, 2300.99},
    {"HP Spectre", 3800, 2000.99},
    {"Dell Inspiron", 3200, 2000.99},
    {"Asus TUF", 3000, 2000.99},
    {"MacBook Air", 3500, 2000.99},
    {"Alienware X17", 4200, 3000.00},
    {"Gigabyte Aero", 3900, 2100.00},
    {"Lenovo Legion", 3700, 1900.00},
    {"Asus ZenBook", 3300, 1500.00},
    {"MSI Creator", 3100, 2500.00}
};

	sortByName(arr);
	cout <<"bai a: "<< endl;
	display(arr);

	sortBySpeed(arr);
    cout <<"bai b: "<< endl;
	display(arr);

    SortPrice(arr);
    cout <<"bai c: "<< endl;
	display(arr);

    cout <<"bai d: "<< endl;
    int p1 = 1900, p2 = 2000;
    int s1 = 2500, s2 = 3000;
	filter(arr, 1800, 2500, 3000, 4000);
	return 0;
}
