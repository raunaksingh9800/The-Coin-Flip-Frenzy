#include<iostream>
#include <random>
using namespace std;


/*
If you flip a coin 5 times, what is the probability of getting at least 3 heads?
*/



class problem {
    private:
        bool coin[5];   // [true,false,true,true,false] || coin[5] stores the 5 possible outcomes
        int hORt,headcounter; // hORt is used to store the value given by Randome GenEng, headcounter stores how many times in coin[5] heads has Occurred more than 3 times
    public:
        problem() { //constructor
            for (int i = 0; i < 6; i++)
            {
                // Random Value generator START
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dist(0, 1);
                // Random Value generator END
                

                int hORt = dist(gen);// store the random value
                
                /*
                True,1 -> is equals to tails
                False,0 -> is equals to heads
                */

                if (hORt==1)
                {
                    coin[i] = true;
                }
                else if (hORt==0)
                {
                    coin[i] = false;
                }
                        
            }
        }

        bool check(){
            for (int i = 0; i < 6; i++)
            {
                if(coin[i]==false){ // if heads at index of coin[5], increment headcounter
                    headcounter++;
                }
            }
            if (headcounter>=3)// if heads more then 3 times in coin[5] return true which means in this event head has occured more then 3 times
            {
                return true;
            }
            else {
                return false;//return false if not more then 3
            }
            
        }

        ~problem() {// destructor, set values to 0
            for (int i = 0; i < 6; i++)
            {
                coin[i] = false;
            }
            hORt = 0;
            headcounter = 0;
            
        }

};


int main() {

    int probcounter=0,n=0; // probcounter to stores the total number of times head occurred more then 3 times, n for number of events
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        problem slove;
        if (slove.check())// if true, which means headcounter>=3 then probcounter+1
        {
            probcounter++;
        }
        
    }
    
    float prob = float(probcounter)/float(n);// calculate prob 
    cout<<endl<<prob<<endl;

    return 0;
}