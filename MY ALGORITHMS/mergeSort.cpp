#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[l+i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid+i+1];

    int i = 0; int j = 0; int K = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j]) arr[K] = L[i++];
        else arr[K] = R[j++];
        K++;
    }
    while(i < n1) arr[K++] = L[i++];
    while(j < n2) arr[K++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
int main()
{
    ifstream cin("outofplace.in");
    ofstream cout("outofplace.out");
    //ifstream cin("input.txt");
    int N;

    cin >> N;

    vector<int> arr(N);
    vector<int> finalArr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        finalArr[i] = arr[i];
    } 
    mergeSort(finalArr,0,N-1);
    int cannotlivewithoutfentanyl = 0;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] != finalArr[i]) cannotlivewithoutfentanyl++;
    } 
    cout << cannotlivewithoutfentanyl-1 << "\n";
    return 0;
}