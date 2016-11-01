/*
2.10 寻找数组中的最大值和最小值
*/

struct MaxMin {
	int max;
	int min;
};

MaxMin getMaxIn(int *arr, int b, int e)
{
	Maxmin m;

	if (e-b <= 1) {
		if (arr[b] < arr[e]) {
			m.max = arr[e];
			m.min = arr[b];
		} else {
			m.max = arr[b];
			m.min = arr[e];
		}
	}

	m = getMaxin

}

 struct Res{
         
    int max ;
    int min ;
    Res(int max , int min):max(max) , min(min) {}     
    Res() {}
  } ;
  
  Res maxmin(int * arr , int low , int high)
  {
    int i = low ;
    int j = high ;
    if(i < j)
    {
     
      if(i == j - 1)
      {
        if(arr[i] < arr[j])
          return Res(arr[j] , arr[i]) ;
        else
          return Res(arr[i] , arr[j]) ;       
      }
          
      int mid = (i + j ) >> 1;
       Res left  = maxmin(arr , low , mid) ;
       Res right = maxmin(arr , mid + 1 ,high) ;   
       
       Res res ;
       
       if(left.max > right.max)
         res.max = left.max ;
       else
         res.max = right.max ;
         
       if(left.min > right.min)
         res.min = right.min ;
       else
         res.min = left.min ;
         
       return res;       
          
    }


    int main()
  {
    int arr[] = {6 , 5 , 8 ,3 , 9 ,7} ;
    Res res = maxmin(arr , 0 , 5) ;
    cout<<res.max<<" "<<res.min<<endl ;
    getchar() ; 
    return 0 ;    
  }



  /*
  求取数组中的第二大的数字 , 也可以两两比较
  但是不能使用分治法 
*/

#include <iostream>
 using namespace std ;
 
 int max2(int * arr , int n)
 {
   if(!arr || !n )
     return -1;
     
    int begin ;
    int max1 , max2; //存储最大值和最小值 
    
    if(n & 1) //奇数 
     {
       begin = 1;     
       max1 = max2 = arr[0] ;          
     }
    else
    {
        begin = 2;
       if(arr[0] > arr[1])
        {
          max1 = arr[0] ;
          max2 = arr[1] ;        
        }    
        else
        {
           max1 = arr[1] ;
           max2 = arr[0] ;                    
        } 
    } 
    
    for(int i = begin ; i < n ; i += 2)
    {
      int m1 , m2 ;      
      if(arr[i] > arr[i + 1]) //1次比较 
        {
          m1 = arr[i] ;
          m2 = arr[i+1] ;                 
        }    
      else
        {
          m1 = arr[i+1] ;
          m2 = arr[i] ;   
        }    
        
        if(m1 > max1)  //比较2次大小 
        {
          max1 = m1 ;
          if(m2 > max1)
            max2 = m2 ;
          else
            max2 = max1 ;                
        }
        else //m1 < max1
        {
           if(m1 > max2) 
              max2 = m1 ;
           
            
        } 
            
    }
      
    return max2 ;
    
 } 
 
 
 int main()
 {
     int arr[] = {5 , 6 ,8 , 3 , 7 ,9} ;
     int m = max2(arr , 5) ;
     cout<<m<<endl ;
     getchar() ;
     return 0 ;    
 }
