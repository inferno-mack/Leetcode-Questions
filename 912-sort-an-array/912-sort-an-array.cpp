class Solution {
public:
    void merge(vector<int>& v , int low , int mid , int high)
    {
        int i = low ;
        int j = mid + 1 ;
        
        vector<int> v1 ;
        
        while(i<=mid&&j<=high)
        {
            if(v[i]<=v[j])
            {
                v1.push_back(v[i]) ;
                i++ ;
            }
            else
            {
                v1.push_back(v[j]) ;
                j++ ;
            }
        }
        
        while(i<=mid)
        {
            v1.push_back(v[i]) ;
            i++ ;
        }
        
        while(j<=high)
        {
            v1.push_back(v[j]) ;
            j++ ;
        }
        
        int curr = 0 ;
        
        for(i=low;i<=high;i++)
        {
            v[i] = v1[curr] ;
            curr++ ;
        }
    }
    
    void mergesort(vector<int>&v , int low , int high)
    {
        if(low<high)
        {
            int mid = low + (high-low)/2 ;
            
            mergesort(v,low,mid) ;
            mergesort(v,mid+1,high) ;
            merge(v,low,mid,high) ;
        }
    }
    
    vector<int> sortArray(vector<int>& v) {
        mergesort(v,0,v.size()-1) ;
        
        return v ;
    }
};