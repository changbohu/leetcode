class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        //try any number of candy's from the first
        
        int n= ratings.size();
        if (n<=1) return n;
        
        //n>>2
        int sum=1;
        int candy=1;
        int down=0;
        int delta=0;
        
        for (int i=1; i<n; i++){
            if (down)
            {
                if (ratings[i]<ratings[i-1]){
                    candy--;
                    sum+=candy;
                    delta=1-candy;
                    down++; 
                }
                    
                if (ratings[i]>ratings[i-1]){  //droping stoped
                   candy=2;
                   if (delta>=0)
                     sum+=(down+1)*delta+candy;  //fill up the lowest and before,which is at i-1 and previou down,curcandy =2,adjust sum
                   else 
                     sum+=(down)*delta+candy;
                   down=0; 
                }
                if (ratings[i]==ratings[i-1]){
                  // delta=1-candy;
                   candy=1;
                   
                  if (delta>=0) 
                   sum+=(down+1)*delta+candy;  //fill up the lowest and before,which is at i-1 and previou down, curcandy=1,adjust sum
                   else 
                     sum+=(down)*delta+candy;
                     
                   down=0; 
                }
            }
            else{// prvious is not dropping
                if (ratings[i]<ratings[i-1]){ //dropping start
                    candy--;
                    sum+=candy;
                    down=1;
                    delta=(1-candy);
                }
                    
                if (ratings[i]>ratings[i-1]){  //
                   candy++;
                   sum+=candy; 
                   down=0; 
                   
                }
                if (ratings[i]==ratings[i-1]){
                   candy=1;
                   sum+=candy;  
                   down=0; 
                }
            }
            
        }//end for
        //process down until the last, do correction
        if (down){
            if (delta>=0)
             sum+=(down+1)*delta;  //fill up the lowest and before,which is at i-1 and previou dropn,curcandy =2,adjust sum
             else
             sum+=down*delta;
        }
        return sum;
        ;
    }
};