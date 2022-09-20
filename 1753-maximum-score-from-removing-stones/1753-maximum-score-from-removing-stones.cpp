class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        
        sort(temp.begin(), temp.end());
        if((temp[0]+temp[1]<temp[2])){
            return (temp[0]+temp[1]);
        }
        else if((temp[0]+temp[1]==temp[2])){
            return temp[2];
        }
        else{
            int sum=0;
            sum+=abs(temp[1]+temp[0]-temp[2])/2;
            sum+=temp[2];
            return sum;
        }
        return -1;
    }
};