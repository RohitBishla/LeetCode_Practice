class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) //+ve in stack -> <- takrayenge
    {
        int n = a.size();
        vector<int> v;
        
        for(int i=0; i<n; i++)
        {
            if(v.empty() || v.back() < 0 || a[i] > 0)
                v.push_back(a[i]);
            
            else if(v.back() < -a[i])           //v.back() > 0 and a[i] < 0
            {
                i--;                     
                v.pop_back();       
            }                                
            else if(v.back() == -a[i])          //both destroyed
                v.pop_back();  
        }
        return v;
    }
};