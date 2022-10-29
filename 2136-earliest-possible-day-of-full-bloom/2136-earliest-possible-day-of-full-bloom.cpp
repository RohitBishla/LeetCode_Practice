class Solution {
    void merge(vector<int>& arr, int &start, int &end, vector<int>& two){
        int mid = (end + start)/2;
        vector<int> temp, temp2;
        int i = start, j = mid + 1;
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                temp2.push_back(two[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                temp2.push_back(two[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(arr[i]);
            temp2.push_back(two[i]);
            i++;
        }
        while(j <= end){
            temp.push_back(arr[j]);
            temp2.push_back(two[j]);
            j++;
        }
        i = start;
        int k = 0;
        while(i <= end){
            arr[i] = temp[k];
            two[i] = temp2[k++];
            i++;
        }
    }
    
    
    void mergeSort(vector<int>& arr, int start, int end, vector<int>& two){
        if(start >= end){
            return;
        }
        int mid = (end + start)/2;
        mergeSort(arr, start, mid, two);
        mergeSort(arr, mid + 1, end, two);
        // merge(arr, start, end, two);
        vector<int> temp(end - start + 1), temp2(end - start + 1);
        int i = start, j = mid + 1, k = 0;
        
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp[k] = arr[i];
                temp2[k++] = two[i];
                i++;
            }
            else{
                temp[k] = arr[j];
                temp2[k++] = two[j];
                j++;
            }
        }
        while(i <= mid){
            temp[k] = arr[i];
            temp2[k++] = two[i];
            i++;
        }
        while(j <= end){
            temp[k] = arr[j];
            temp2[k++] = two[j];
            j++;
        }
        i = start;
        k = 0;
        while(i <= end){
            arr[i] = temp[k];
            two[i] = temp2[k++];
            i++;
        }
    }

public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        mergeSort(growTime, 0, plantTime.size() - 1, plantTime);

        int last = 0;
        int ans = 0;
        for(int i = plantTime.size() - 1; i >= 0; i--){
            ans = max(ans, last + plantTime[i] + growTime[i]);
            last = last + plantTime[i];
        }
        return ans;
    }
};


// 0112
// .0012
// ...000112
// ......0012
// 0123456789