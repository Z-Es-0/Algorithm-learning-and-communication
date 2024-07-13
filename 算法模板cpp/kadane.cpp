int kadane(const vector<int> arr,int x){
    int cmax=arr[0];
    int gmax=arr[0];
    for (int i = 1; i < x; ++i) {
        cmax=max(arr[i],cmax+arr[i]);
        gmax=max(gmax,cmax);
    }
    return gmax;

}