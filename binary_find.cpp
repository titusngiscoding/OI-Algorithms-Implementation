template <typename T>
int binaryFind(T *arr,T *end, T target)
{
    int low=0;
    int high=end-arr;
    int mid=(high+low)/2;
    while(low!=high)
	{
    	if(target<arr[mid])
    		high=mid;
		else if(target>arr[mid])
			low=mid+1;
		else
			return mid;
			
		mid=(high+low)/2;
	}
    return -1;
}

