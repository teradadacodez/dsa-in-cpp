#include <bits/stdc++.h>
using namespace std;

class myarray
{
    int arr[10] = {1,2,3,4,5} ; 
    int len {5} ; // tells how many elements are filled

    public :
    int getlen()
    {
        return len ;
    }
    void display()
    {
        for(int i {0} ; i<10 ; i++) cout << arr[i] << " " ; cout << endl;
    }
    void append(int x)
    {
        arr[len] = x ;
        len++ ;
    }
    void insert(int ind , int x)
    {
        for(int i {len} ; i>ind ; i--)
        {
            arr[i] = arr[i-1] ;
        }
        arr[ind] = x ;
        len++ ;
    }
    int pop(int ind)
    {
        if(ind>=len || ind<0) return -1 ;
        int x = arr[ind] ;
        for(int i {ind} ; i<len ; i++)
        {
            arr[i] = arr[i+1] ;
        }
        len-- ;
        return x ;
    }
    int linearsearch(int x)
    {
        for(int i {0} ; i<len ; i++)
        {
            if(x == arr[i]) return i ;
        }
        return -1 ;
    }
    bool issorted()
    {
        for(int i {0} ; i<len-1 ; i++)
        {
            if(arr[i]>arr[i+1]) return false ;
        }
        return true ;
    }
    int binarysearch(int x)
    {
        if(!issorted()) return -1 ;
        int l {0} , h {len-1} , mid ;
        while(l<=h)
        {
            mid = (l+h)/2 ;
            if(x == arr[mid]) return mid ;
            if(arr[mid] < x) l = mid+1 ;
            else h = mid-1 ;
        }
        return -1 ;
    }
    int recursivebinarysearch(int x , int low , int high)
    {
        if(!issorted()) return -1 ;
        if(low>high) return -1 ;
        int mid {(low+high)/2} ;
        if(arr[mid] == x) return mid ;
        if(arr[mid]<x) return recursivebinarysearch(x,mid+1,high) ;
        else return recursivebinarysearch(x,low,mid-1) ;
    }
    int get(int ind)
    {
        if(ind<0 || ind>len-1) return -1 ;
        return arr[ind] ;
    }
    string set(int ind , int x)
    {
        if(ind<0 || ind>len-1) return "Index out of range" ;
        arr[ind] = x ;
        return "Set Successful" ;
    }
    pair<int,int> maxmin()
    {
        int mx {arr[0]} , mn {arr[0]} ;
        for(int i {0} ; i<len ; i++)
        {
            if(arr[i]>mx) mx = arr[i] ;
            if(arr[i]<mn) mn = arr[i] ;
        }
        return {mx,mn} ;

    }
    pair<int,double> sumavg()
    {
        int sum {0} ;
        for(auto i : arr) sum+=i ;
        return {sum , (double)sum/len} ;
    }
    void reverse()
    {
        int *b ; // we used heap memory 
        b = new int[10] ;
        for(int i {len-1},j {0} ; i>=0 ; i-- , j++) b[j] = arr[i] ;
        for(int i {0} ; i<len ; i++) arr[i] = b[i] ;
        delete[] b ; // after use we deleted it !!
    }
    int leftshift()
    {
        int x {arr[0]} ;
        for(int i {0} ; i<len ; i++) arr[i] = arr[i+1] ;
        len-- ;
        return x ;
    }
    void rotateleft()
    {
        int x {arr[0]} ;
        for(int i {1} ; i<len ; i++) arr[i-1] = arr[i] ;
        arr[len-1] = x ;
    }
    void insertsort(int x)
    {
        if(!issorted()) return ;
        if(len == 10) return ;
        int i {len-1} ;
        while(i>=0 && arr[i]>x)
        {
            arr[i+1] = arr[i] ;
            i-- ;    
        }
        arr[i+1] = x ;
        len++ ;
    }   
} ;

int main()
{
    myarray arr  ;
    arr.display() ;
    arr.append(10) ;
    arr.display() ;
    arr.insert(4,20) ;
    arr.display() ;
    cout << "deleted element : " << arr.pop(4) << endl;
    arr.display() ;
    cout << arr.linearsearch(4) << endl;
    cout << arr.binarysearch(4) << endl;
    cout << arr.recursivebinarysearch(7,0,arr.getlen()) << endl;
    auto k {arr.maxmin()} ;
    cout << k.first << " " << k.second << endl;
    auto l {arr.sumavg()} ;
    cout << l.first << " " << l.second << endl;
    cout << "before reverse" << endl;
    arr.reverse() ;
    cout << "after reverse" << endl;
    arr.display() ;
    cout << "left shift" << endl;
    arr.leftshift() ;
    arr.display() ;
    arr.rotateleft() ;
    arr.display() ;
}