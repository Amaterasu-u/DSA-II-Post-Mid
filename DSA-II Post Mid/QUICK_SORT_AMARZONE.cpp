#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int roll;
    int marksDSA;
    int marksC;
    int credits;
};

int getinfo(const Student &a) {
    if(a.credits >= 40) {
        return a.marksDSA;
    } else {
        return a.marksC;
    }
}

int Partition(vector<Student> &arr, int p, int r) {

    int pivot = getinfo(arr[r]);
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if(getinfo(arr[j]) <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i + 1;
}

void QuickSort(vector<Student> &arr, int p, int r) {
    if(p < r) {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<Student> students(n);
    
    for(int i = 0; i < n; i++){
        cin >> students[i].name >> students[i].roll >> students[i].marksDSA 
            >> students[i].marksC >> students[i].credits;
    }

    QuickSort(students, 0, n - 1);
    
    for(auto &s : students) {
        cout << s.name << " ";
    }
    cout << endl;
    
}
