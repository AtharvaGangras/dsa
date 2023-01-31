   int size = intervals.size();
    int i = 0;
    int counter = 1;
    while(i<size)//first loop chooses the element.
    {
        counter = 1; // jump counter.
        //now using the second loop to merge intervals
        for(int j = i+1; j<size;j++)
        {
            if(intervals[i][1]>=intervals[j][0])
            {
                if(intervals[i][1]<intervals[j][1]) intervals[i][1] = intervals[j][1]; 
                counter++;
            }
            else{
                break;
            }
        }
        sol.push_back(intervals[i]);//putting into solution
        i += counter;
    }
    return sol;