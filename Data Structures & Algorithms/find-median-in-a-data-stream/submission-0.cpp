class MedianFinder {
public:

    vector<int>arr;
    double mid = 0.0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
        sort(arr.begin(), arr.end());

        int n = arr.size();
        if(n % 2 == 1){
            mid = arr[n/2];
        }else{
            mid = double(arr[n/2] + arr[(n/2)-1] )/2;
        }


    }
    
    double findMedian() {
        return mid;
    }
};
