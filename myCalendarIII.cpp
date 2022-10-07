class MyCalendarThree {
public:
    map <int,int> mp;
    MyCalendarThree() {
	    mp.clear();
        return;
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int val=0,mmax=0;
        for (auto p:mp){
          val+=p.second,mmax=max(mmax,val);  
        } 
        return mmax;
    }
};
