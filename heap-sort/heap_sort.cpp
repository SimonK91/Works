#include <vector>
#include <algorithm>

#define DEBUG false
template<class T, typename Fn>
void heap_sort(std::vector<T>& vec, Fn func)
{

    //fixing the heap
    for(int i = 0 ; i < vec.size() ; ++i)
    {
	int temp = i+1;
	while(temp != 1 && func(vec[temp/2-1],vec[temp-1]))
	{
	    std::swap(vec[temp-1],vec[temp/2-1]);
	    temp /= 2;
	    if(DEBUG)
	    {
		std::cout << "inserting: " << i << std::endl;
		for(auto it : vec)
		{
		    std::cout  << std::endl << it << std::endl;
		}
		std::cout << std::endl;
	    }
	}
    }
    if(DEBUG)
    {
	std::cout << "heap fixed:" << std::endl;
	for(auto it : vec)
	{
	    std::cout << std::endl << it << std::endl;
	}
	std::cout << std::endl;
    }
    //sorting the heap
    for(int i = vec.size() ; i > 1 ; --i)
    {
	std::swap(vec[0],vec[i-1]);

	if(DEBUG)
	{
	    std::cout << "swapping with last" << std::endl;
	    for(auto it : vec)
	    {
		std::cout << std::endl << it << std::endl;
	    }
	    std::cout << std::endl;
	}
	int temp = 1;
	while( (temp*2   < i && func(vec[temp-1],vec[temp*2-1])  ) ||
	       (temp*2+1 < i && func(vec[temp-1],vec[temp*2]))  )
	{
	    int temp2;
	    if(temp*2+1 < i && func(vec[temp*2-1],vec[temp*2]))
	    {
		temp2 = temp*2+1;
	    }
	    else
	    {
		temp2 = temp*2;
	    }
	    std::swap(vec[temp-1],vec[temp2-1]);

	    if(DEBUG)
	    {
		std::cout << "Element: " << i << " sorted" << std::endl;
		for(auto it : vec)
		{
		    std::cout << std::endl << it << std::endl;
		}
		std::cout << std::endl;

		std::cout << temp << " " << temp2 << std::endl;
	    }
	    temp = temp2;
	}
    }
}
