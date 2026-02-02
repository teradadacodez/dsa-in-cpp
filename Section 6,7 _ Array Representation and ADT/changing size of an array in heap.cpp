#include <bits/stdc++.h>
using namespace std;
// static arrays cannot increase their size but 
// there is an alternative in heap using pointers !!
int main()
{
    int *p , *q ;
    p = new int[5] ;
    for(int i {0} ; i<5 ; i++) p[i] = i+1 ;
    // but now we want to add more elements in p only
    // i.e. we do not want to change even the name of the pointer p
    // so we create a new pointer q with increased size 
    // and then assign the elements of p to q 
    // then free the memory p is pointing to and 
    // reassign p to q ;
    // then delete q (if you want) because q is not taking 
    // extra memory (in heap) it's just two different 
    // pointer pointing to same locations !!!
    q = new int[10] ;
    for(int i {0} ; i<5 ; i++) q[i] = p[i] ;
    delete[] p ; // or free(p) 
    p = q ; // to reassign p to q we first have to delete or free p 

    // since q not deleted this for loop will work !
    for(int i {0} ; i<10 ; i++) cout << "at " << q+i << " : " << *(q+i) << endl;
    // since only first five elements are copied , rest are garbage !
    // now we can "delete[] q ;" or make "q = null ;"
    // IF WE DELETE q THEN p WILL ALSO GET AFFECTED SINCE 
    // THEY BOTH ARE POINTING TO SAME MEMORY LOCATION 
    // AND REMEMBER PLAYING WITH POINTERS IS EQUAL TO 
    // PLAYING WITH VARIABLES PASSED BY REFERENCE !!!
    q = nullptr ;   
    // now q is just a pointer variable in stack with a random address 
    // now if we try to print q then 
    // now q deleted above for loop will not work instead we have to do this 
    for(int i {0} ; i<10 ; i++) cout << *(p+i) << " " ; cout << endl;

    // SO WE HAVE INDIRECTLY INCREASED THE SIZE OF P !!!
}